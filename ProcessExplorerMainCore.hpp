#include "StdAfx.h"

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>

using namespace std;

int KillProcess(DWORD dwProcessId)
{

  GetProcAddress(GetModuleHandle(TEXT("Kernel")),"OpenProcess");

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwProcessId); //�򿪽��̵õ����̾��
    if(hProcess == NULL)
    {
      printf("�򿪲����ʽ���ʱ����δ֪����\n");
      std :: cout << "OpanProcess Error!"  << endl;
      getchar();
      return 0;
    }
    if(TerminateProcess(hProcess,0))
    {
      printf("�������̳ɹ�\n");
      std :: cout << "EndProcess Done!"  << endl;
      getchar();
      return 0;
    }
    else
    {
      printf("��������ʧ��\n");
      std :: cout << "EndProcess Failed!"  << endl;
      getchar();
      return 0;
    }
}

int GetProcess()
{

    char buff[2048] = {0};
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0); //���ϵͳ�����н��̿���

           if(hProcessSnap == INVALID_HANDLE_VALUE)
           {
           printf("����ϵͳ���̿��շ���δ֪����\n");
           std :: cout << "Create System Snapshot Error" << endl;
           getchar();
           return 0;
           }

           BOOL bProcess = Process32First(hProcessSnap,&pe32);
           while(bProcess)
           {
           	     wsprintf(buff,"%s <--------> PID:%d\r\n",pe32.szExeFile,pe32.th32ProcessID);
           	     //��ʽ���������ͽ���ID
				 printf(buff); //����������ͽ���ID
				 memset(buff,0x00,1024);
				 bProcess = Process32Next(hProcessSnap,&pe32); //�����оٽ���
           }
     CloseHandle(hProcessSnap);
     return 0;
}
