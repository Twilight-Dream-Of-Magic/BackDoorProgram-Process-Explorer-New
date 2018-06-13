#include "StdAfx.h"

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>

using namespace std;

int CreateProcessFromBinaryFile()
{
    //Wait for new code
    return 0;
}

int KillProcess(DWORD doubleWord_ProcessIdentity)
{

	GetProcAddress(GetModuleHandle(TEXT("Kernel")),"OpenProcess");

	HANDLE handle_Process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,doubleWord_ProcessIdentity); //�򿪽��̵õ����̾��
	if(handle_Process == NULL)
	{
		printf("�򿪲����ʽ���ʱ����δ֪����\n");
		std :: cout << "Open Process Error!"  << endl;
		getchar();
		return 0;
	}
	if(TerminateProcess(handle_Process,0))
	{
		printf("�������̳ɹ�\n");
		std :: cout << "End Process Done!"  << endl;
		getchar();
		return 0;
	}
	else
	{
		printf("��������ʧ��\n");
		std :: cout << "End Process Failed!"  << endl;
		getchar();
		return 0;
	}
}

int ProcessList()
{

	char buffer[2048] = {0};
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE handle_ProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0); //Get a snapshot of all processes inside the system ���ϵͳ�ڲ����еĽ��̿���

		if(handle_ProcessSnapshot == INVALID_HANDLE_VALUE)
		{
		printf("����ϵͳ���̿��շ���δ֪����\n");
		std :: cout << "Create System Snapshot Error" << endl;
		getchar();
		return 0;
		}

		BOOL boolean_Process = Process32First(handle_ProcessSnapshot,&pe32);
		while(boolean_Process)
		{
			wsprintf(buffer,"%s <--------> PID:%d\r\n",pe32.szExeFile,pe32.th32ProcessID);
			//Formatting process name and process ID ��ʽ���������ƺͽ���ID
			printf(buffer); //List process name and process ID ����������ƺͽ���ID
			memset(buffer,0x00,2048); //Buffer variable to clear memory data, data is overwritten with hexadecimal 00 �����ڴ����ݵĻ��������������ݸ���Ϊʮ������00
			boolean_Process = Process32Next(handle_ProcessSnapshot,&pe32); //�����оٽ���
		}

	CloseHandle(handle_ProcessSnapshot);
	return 0;
}
