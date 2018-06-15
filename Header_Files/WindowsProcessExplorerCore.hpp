#include <iostream>
#include <windows.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <tlhelp32.h>
#include <shellapi.h>

#include "StdAfx.h"
#include "CharacterCoderConvert.hpp"

using namespace std;

/*Process management functions*/

int CreateProcessFromBinaryFile(LPSTR BinaryFileCommand)
{

	//wchar_t *WCT_BFC = StringToWideCharacter(BFC,CP_ACP);
	//wchar_t *WCT_CP = StringToWideCharacter(CP,CP_ACP);

	//char *CharacterPointer_BFC = WideCharacterToNarrowCharacter(WCT_BFC,CP_ACP);
	//char *Character_CP = WideCharacterToNarrowCharacter(WCT_CP,CP_ACP);

	//char Character_BFC[] = {""};
	//memcpy(Character_BFC, CharacterPointer_BFC, sizeof(Character_BFC)); //Character Pointer Convert To Character Array

	/*
	#ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, Character_BFC, -1, BinaryFileCommand, BinaryFileCommand.sizeof());
    #else
    strcpy(BinaryFileCommand, Character_BFC);
    #endif
    */

    printf("Argument vector inside funcion: %s\n",BinaryFileCommand);

	STARTUPINFO si = {sizeof(si)};
	memset(&si, 0, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

	PROCESS_INFORMATION pi;
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));

    if(!CreateProcess(/*Binary file full path name*/               NULL,
                      /*Command line parameter*/                   BinaryFileCommand,
                      /*Process handle not inheritable*/           NULL,
                      /*Process handle not inheritable*/           NULL,
                      /*Set handle inheritance to FALSE*/          FALSE,
                      /*Process flags (CREATE_NO_WINDOW) */        NULL,
                      /*Use parent's environment block*/           NULL,
                      /*Use parent's starting directory*/          NULL,
                      /*Pointer to STARTUPINFO structure*/         &si,
                      /*Pointer to PROCESS_INFORMATION structure*/ &pi
                      )
      )
    {
        printf("System create process failed:\n");
        printf("Error code:%d\n",GetLastError());
        return 1;
    }
	else
	{

		std :: cout << "The system created a process. ID:" << pi.dwProcessId<< "\n" << endl;
		std :: cout << "The system created a thread. ID:" << pi.dwThreadId << "\n" << endl;
		std :: cout << "ϵͳ������һ�����̣�ID��" << pi.dwProcessId << "\n" << endl;
		std :: cout << "ϵͳ������һ���̣߳�ID��" << pi.dwThreadId << "\n" << endl;

		//Wait until child process exits.
        //WaitForSingleObject( pi.hProcess, INFINITE );
        //printf("\nThis process ID: %d has been terminated!",pi.dwProcessId);

		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);

	}
	system("pause");
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
		printf("����ϵͳ���̿��գ�����δ֪����\n");
		std :: cout << "A snapshot of the system process was not created and an unknown error occurred" << endl;
		getchar();
		return 0;
	}
	BOOL boolean_Process = Process32First(handle_ProcessSnapshot,&pe32);
	while(boolean_Process)
	{
		wsprintf(buffer,"%s <----> PID:%d\r\n",pe32.szExeFile,pe32.th32ProcessID);
		//Formatting process name and process ID ��ʽ���������ƺͽ���ID
		printf(buffer); //List process name and process ID ����������ƺͽ���ID
		memset(buffer,0x00,2048); //Buffer variable to clear memory data, data is overwritten with hexadecimal 00 �����ڴ����ݵĻ��������������ݸ���Ϊʮ������00
		boolean_Process = Process32Next(handle_ProcessSnapshot,&pe32); //�����оٽ���
	}
	CloseHandle(handle_ProcessSnapshot);

	/*
	HANDLE handle_ProcessCommandLine = GetCommandLine();
	if(handle_ProcessCommandLine == INVALID_HANDLE_VALUE)
	{
			printf("��ȡϵͳ���������У�����δ֪����\n");
			std :: cout << "Get system process command line, unknown error has occurred" << endl;
			getchar();
			return 0;
	}
	BOOL handle_ProcessCommandLine = Process32First(handle_ProcessSnapshot,&pe32);
	while(handle_ProcessCommandLine)
	{
		wsprintf(buffer,"%s <----> CommandLine:%d\r\n",pe32.dwFlags);
		printf(buffer);
		memset(buffer,0x00,2048);
		boolean_Process = Process32Next(handle_ProcessCommandLine,&pe32);
	}
	CloseHandle(handle_ProcessCommandLine);
	*/

	return 0;
}
