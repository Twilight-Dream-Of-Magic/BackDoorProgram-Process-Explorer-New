#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

using namespace std;

int HelpProgramRunTime;

string ProgramMainHelpSystem()
{
     for(HelpProgramRunTime = 0;HelpProgramRunTime <= 1;HelpProgramRunTime++)
     {
     	string KeyboardInput;

        std :: cout << "Please run in Dos CommandLine Mode.\nOtherwise, this program will automatically collapse and exit!" << endl;
        std :: cout << "Intput [Show,SHOW,show],Open This Program Help Info.\nOr Intput [Exit,EXIT,exit] exit program!" << endl;
        std :: cout << "System:/Command/KeyboardInput>";
    	std :: cin >> KeyboardInput;
    	getchar();

    	std :: cout << "----------" <<endl;

    	 if(KeyboardInput == "exit","Exit","EXIT")
         {
           std :: cout << "KeyboardInput [Exit,EXIT,exit],Program will auto exit!" << endl;
           getchar();

           return 0;
         }
         if(KeyboardInput == "Show","SHOW","show")
         {
            std :: cout << "Please run in Dos CommandLine Mode.\n\nTHIS PROGRAM HELP TEXT:\n\nCommand:/showall\nFunction:Show all application processes\nCommand:/killpid (%Program Pid%)\nFunction: Kill a specific application process [Warning: Use in CMD.EXE Command Line Mode!]\n" << endl;
            //�����ַ��������� ʹ�� _T == Unicode�����ַ���

             system("Pause");

              std :: cout << "==========" << endl;
              std :: cout << "THIS PROGRAM HELP TEXT:" << endl;
              std :: cout << "����:/showall\n����:չʾ����Ӧ�ý���" << endl;
              std :: cout << "����:/killpid (%���� ����ID%)\n����:ɱ���ض�Ӧ�ý��� [����:��CMD.EXE������ģʽʹ��!]" << endl;
              std :: cout << "==========" << endl;
              getchar();
              system("Pause");

            break;
         }
         else
         {
             std :: cout << "Keyboard Input String, Load Error.\nThis Program will auto exit!" << endl;
             system("Pause");
             exit(1);
         }
   	 }
  return 0;
}
