// AutoRun_Reg_Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "AutoRun_Reg.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// ��һ�ַ�ʽ�޸�ע���:HKEY_CURRENT_USER
	if (FALSE == Reg_CurrentUser("D:\\WINDOWS�ڿͱ�̼������\\winhack\\�ڴ�ֱ�Ӽ�������\\RunDllInMem_Test\\Debug\\test.exe", "520"))
	{
		printf("Reg_CurrentUser Error!\n");
	}
	// �ڶ��ַ�ʽ�޸�ע���:HKEY_LOCAL_MACHINE
	if (FALSE == Reg_LocalMachine("D:\\WINDOWS�ڿͱ�̼������\\winhack\\�ڴ�ֱ�Ӽ�������\\RunDllInMem_Test\\Debug\\test.exe", "520"))
	{
		printf("Reg_LocalMachine Error!\n");
	}

	printf("Reg OK.\n");

	system("pause");
	return 0;
}

