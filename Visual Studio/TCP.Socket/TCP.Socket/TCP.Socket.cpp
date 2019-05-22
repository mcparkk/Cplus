
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

unsigned int WINAPI RecvThread(void* arg);
unsigned int WINAPI SendThread(void* arg);

//unsigned long _stdcall Thread(void* args)
//{
//	while (true)
//	{
//		char cBuffer[packet_size] = {};
//		recv(sock, cBuffer, packet_size, 0);
//
//		printf("누군가 : %s\n", cBuffer);
//
//	}
//};
unsigned int WINAPI RecvThread(void* arg)
{
	SOCKET sock = (SOCKET)arg;
	char buf[NAMESIZE + MAX_BUF] = { 0 };
	int len = 0;

	while (1)
	{
		len = recv(sock, buf, NAMESIZE + MAX_BUF - 1, 0);

		if (len == -1) return 1;

		buf[len] = 0;
		printf("%s", buf);

	}


	return 0;
}
unsigned int WINAPI SendThread(void* arg)
{
	SOCKET sock = (SOCKET)arg;
	char buf[NAMESIZE + MAX_BUF] = { 0 };
	char str[MAX_BUF] = { 0 };

	while (1)
	{
		fgets(str, MAX_BUF, stdin);
		if (strcmp(str, "q\n") == 0)
		{
			
			exit(0);
		}

		printf(buf, "%s", str);
		send(sock, buf, strlen(buf), 0);

	}

	closesocket(sock);

	return 0;
}


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
	
		

	/*while (true)
	{
		char cMsg[10000];
		cin >> cMsg;
		strcat_s(cMsg, "\n");
		send(sock, cMsg, strlen(cMsg), 0);

		char cBuffer[packet_size] = {};
		recv(sock, cBuffer, packet_size, 0);

		printf("누군가 : %s\n", cBuffer);

	}*/
	HANDLE hThreadSend = 0;
	HANDLE hThreadRecv = 0;		//스레드 핸들
	DWORD dwdSend = 0;
	DWORD dwdRecv = 0;			//스레드 아이디		

	hThreadSend = (HANDLE)_beginthreadex(NULL, 0, RecvThread, (void*)sock, 0, (unsigned int*)& dwdSend);
	hThreadRecv = (HANDLE)_beginthreadex(NULL, 0, SendThread, (void*)sock, 0, (unsigned int*)& dwdRecv);
	
	
	CloseHandle(hThreadSend);
	CloseHandle(hThreadRecv);

	closesocket(sock);
	WSACleanup();



	return 0;
	
	
	
	/*while (true)
	{
	
		hThread = CreateThread(NULL, 0, 0, (void*)sock, theadID, NULL);

		char cMsg[10000];
		cin >> cMsg;
		strcat_s(cMsg, "\n");
		send(sock, cMsg, strlen(cMsg), 0);

	}*/
	

	/*char cMsg[] = "mincheol\n";
	send(sock, cMsg, strlen(cMsg), 0);*/

	

	//메세지 출력
	
}


