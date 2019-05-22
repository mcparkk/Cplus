
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <process.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

#define Port 9999
#define packet_size 4096
#define serverip "10.10.14.58"
#define NAMESIZE 64
#define MAX_BUF  256

DWORD WINAPI SendThread(LPVOID lpData);

#define BUFFERSIZE 1024


int main()
{

	printf("============================채팅==============================\n");
	//-------------------------------------------------------------------------------------1.윈속 초기화
	WSADATA wsaData;
	// int WSAStartup(WORD WversionRequested, LPWSADATA IpWSAData);  초기화 함수 포멧 
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//-------------------------------------------------------------------------------------2.소켓생성
	// 소켓 생성 함수 
	// socket(af-주소체계 , type-소켓타입, protocol - 프로토콜 타입)
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//-------------------------------------------------------------------------------------3.데이터통신
	//소켓 주소 구조체를 활용하여 주소 체계 확립

	SOCKADDR_IN sockinfo;
	sockinfo.sin_family = AF_INET;				//주소체계정보
	sockinfo.sin_port = htons(Port);			//포트정보
	//sockinfo.sin_addr.s_addr = inet_addr(serverip);		// 서버 아이피 정보 & (INADDR_ANY -모든 사용가능한 주소로부터 대기)
	inet_pton(AF_INET, serverip, &sockinfo.sin_addr);
	//connect - 서버측에 소켓을 기반으로 연결을 요청할 때 사용하는 함수 
	//connect(클라이언트소켓,(SOCKADDR*)&서버주소구조체,sizeof(서버주소구조체)


	//connect(sock, (sockaddr*)& sockinfo, sizeof(sockinfo));
	if (connect(sock, (sockaddr*)& sockinfo, sizeof(sockinfo)) != SOCKET_ERROR)
		printf("서버에 접속하였습니다.^ㅇ^\n");
	else
		printf("서버 접속 실패ㅠㅠ\n");

	//string clientmessage ;



	
	//HANDLE hThreadSend = 0;
	//HANDLE hThreadRecv = 0;		//스레드 핸들
	//DWORD dwdSend = 0;
	//DWORD dwdRecv = 0;			//스레드 아이디		

	CreateThread(NULL, 0, SendThread, (LPVOID)sock, 0, NULL);
	// 상태 출력
	DWORD dwTmp;
	char text[1024] = "서버에 접속되었습니다.\n";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), text, strlen(text), &dwTmp, NULL);
	// 전송 & 수신 루푸
	while (true)
	{
		char buffer[1024] = { 0 };
		int len = recv(sock, buffer, sizeof(buffer), 0);
		if (len <= 0)
		{
			printf("접속 종료.");
			break;
		}
		// 메시지 출력
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &dwTmp, NULL);
	}






	//CloseHandle(hThreadSend);
	//CloseHandle(hThreadRecv);

	closesocket(sock);

	//WSACleanup();

	return 0;
}



DWORD WINAPI SendThread(LPVOID lpData)
{
	SOCKET socket_client = (SOCKET)lpData;
	while (1)
	{
		printf("전송할 내용 : ");
		DWORD dwTmp;
		string abc;
		char text[BUFFERSIZE] = { 0 };
		ReadFile(GetStdHandle(STD_INPUT_HANDLE), text, 1024, &dwTmp, NULL);
		send(socket_client, text, strlen(text), 0);
	}
	return 0;
}
