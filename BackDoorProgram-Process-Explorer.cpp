#include "ProcessExplorerMainCore.hpp"
#include "StdAfx.h"

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

	if(argc == 2 && strcmp(argv[1],"-showall") == 0)
    {
     GetProcess();
    }
    if(argc == 3 && strcmp(argv[1],"-killpid") == 0)
    {
     KillProcess(atoi(argv[2]));
     /*
      PidNumber = 100
	  atoi() = sting Value(PidNumber) --> int Value(PidNumber)

	  X:\>***.exe argv[1]=Command(-killpid) argv[2]=string(PidNumber)
	 */
    }
     AllocConsole();//Ϊ���̴���һ���µĿ���̨
     SetConsoleTitle("Program Main Help Info");//�޸Ŀ���̨�ı���

     HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨������
     DWORD pointerConsole = 0;
     TCHAR BuffSpace[1024] = {0}; //��������ַ��Ļ�����

     lstrcpy(BuffSpace,_T("Please run in Dos CommandLine Mode.\n\nTHIS PROGRAM HELP TEXT:\n\n����:-showall ����:չʾ����Ӧ�ý���\n\n����:-killpid (%���� ����ID%) ����:ɱ���ض�Ӧ�ý���\n\nCommand:-showall\nFunction:Show all application processes\nCommand:-killpid (%Program Pid%)\nFunction: Kill a specific application process\n\nThis program is compiled by Twlilght_Yujiang\n"));
     //�����ַ��������� ʹ�� _T == Unicode�����ַ���

     WriteConsole(hOutputHandle,BuffSpace,lstrlen(BuffSpace),&pointerConsole,NULL);
	 /*
	 NULL or &pConsole,NULL

	 �ӻ�����������ַ�
	 */

	 CloseHandle(hOutputHandle);
     FreeConsole();//Ϊ�����ͷ�RAM�д����Ŀ���̨
     getchar();
     //return 0;

  /*
   strcmp(a,b)Ϊ�ַ����ȽϺ������Ƚϵ��Ǵ��ַ����ĵ�һ���ַ���ʼ�Ƚ�����ASCLL��ֵ�����ַ����ĳ����޹ء�
   ��a > b ʱ������ֵ > 0
   ��a = b ʱ������ֵ = 0
   ��a < b ʱ������ֵ < 0

   ! ���߼������-->��
   ����ֵΪ��ʱ�ĳɼ٣�ֵΪ��ʱ�ĳ���

   strcmp()�ڳ�����Ƶ��ж������0Ϊ�٣���0Ϊ��

   ������if(!srcmp(A,B))�����������ǿ��Խ�A��B�Ĺ�ϵ��Ϊ���֣�һ����A==B����һ����A!=B
   ��A==Bʱ��strcmp(A,B)Ϊ0��!strcmp(A,B)Ϊ��0��if�ж�Ϊ��
   ��A!=Bʱ��strcmp(A,B)Ϊ��0��!strcmp(A,B)Ϊ0��if�ж�Ϊ��
  */
  return 0;
}
