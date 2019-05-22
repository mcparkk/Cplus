#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>

#define NAMESIZE 64
#define MAX_BUF  256

void Error(const char* mes);
unsigned int WINAPI RecvThread(void* arg);
unsigned int WINAPI SendThread(void* arg);

char name[NAMESIZE] = { 0 };


int main(int argc, char* argv[])
{
	SOCKET hSock = 0;
	SOCKADDR_IN SockAddr = { 0 };
	WSADATA wsaData = { 0 };
	HANDLE hThread1 = 0;
	HANDLE hThread2 = 0;
	DWORD dwth1 = 0, dwth2 = 0;

	if (argc != 4) Error("Program <IP> <PORT> <name>\n");

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) Error("WSAStartup Error\n");

	hSock = socket(PF_INET, SOCK_STREAM, 0);


	sprintf(name, "[%s] ", argv[3]);

	if (hSock == INVALID_SOCKET) Error("socket Error\n");


	memset(&SockAddr, 0, sizeof(SockAddr));
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = inet_addr(argv[1]);
	SockAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSock, (SOCKADDR*)& SockAddr, sizeof(SockAddr)) == SOCKET_ERROR)
		Error("connect Error\n");

	hThread1 = (HANDLE)_beginthreadex(NULL, 0, RecvThread, (void*)hSock, 0, (unsigned int*)& dwth1);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, SendThread, (void*)hSock, 0, (unsigned int*)& dwth2);

	if (hThread2 == 0 || hThread1 == 0)
		Error("_beginthreadex Error\n");

	if (WaitForSingleObject(hThread1, INFINITE) == WAIT_FAILED)
		Error("WaitForSingleObject Error\n");

	if (WaitForSingleObject(hThread2, INFINITE) == WAIT_FAILED)
		Error("WaitForSingleObject Error\n");

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	WSACleanup();
	closesocket(hSock);

	return 0;
}

void Error(const char* mes)
{
	printf("%s\n", mes);
	exit(0);
}

unsigned int WINAPI RecvThread(void* arg)
{
	SOCKET hSock = (SOCKET)arg;
	char buf[NAMESIZE + MAX_BUF] = { 0 };
	int len = 0;

	while (1)
	{
		len = recv(hSock, buf, NAMESIZE + MAX_BUF - 1, 0);

		if (len == -1) return 1;

		buf[len] = 0;
		printf("%s", buf);

	}


	return 0;
}
unsigned int WINAPI SendThread(void* arg)
{
	SOCKET hSock = (SOCKET)arg;
	char buf[NAMESIZE + MAX_BUF] = { 0 };
	char str[MAX_BUF] = { 0 };

	while (1)
	{
		fgets(str, MAX_BUF, stdin);
		if (strcmp(str, "q\n") == 0)
		{
			closesocket(hSock);
			exit(0);
		}

		sprintf(buf, "%s%s", name, str);
		send(hSock, buf, strlen(buf), 0);

	}

	closesocket(hSock);

	return 0;
}