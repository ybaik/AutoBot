#include "winapi.h"

#include <string>
#include <errno.h>

//#include <opencv/cv.h>
//#include <opencv/highgui.h>

#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct CallbackInfo
{
	DWORD m_dwPID;
	HWND m_hWnd;
};

BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam)
{
	DWORD dwPID = 0;
	CallbackInfo *pst_Callback = (CallbackInfo *)lParam;

	GetWindowThreadProcessId(hWnd, &dwPID);

	if (pst_Callback->m_dwPID != dwPID)
		return TRUE;

	pst_Callback->m_hWnd = hWnd;
	return FALSE;
}

HWND GetWindowFromPID(DWORD dwPID)
{
	CallbackInfo st_Callback;

	if (dwPID == 0)
		return NULL;

	st_Callback.m_dwPID = dwPID;
	st_Callback.m_hWnd = NULL;

	EnumWindows(EnumProc, (LPARAM)&st_Callback);

	return st_Callback.m_hWnd;
}

BOOL GetProcessModule(DWORD dwPID, LPCTSTR pszProcessName)
{
	HANDLE        hModuleSnap = NULL;
	MODULEENTRY32 me32        = {0};

	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);

	if (hModuleSnap == (HANDLE)-1)
		return FALSE;

	me32.dwSize = sizeof(MODULEENTRY32);

	if(Module32First(hModuleSnap, &me32))
	{
		do
		{
			printf("%s\n", me32.szModule);
			if(strcmp(me32.szModule, pszProcessName) == 0)
			{
				CloseHandle (hModuleSnap);
				return TRUE;
			}
		}while(Module32Next(hModuleSnap, &me32));
	}

	CloseHandle (hModuleSnap);

	return FALSE;
}

DWORD GetProcessID(LPCTSTR pszProcessName)
{

	HANDLE         hProcessSnap = NULL;
	BOOL           bRet      = FALSE;
	PROCESSENTRY32 pe32      = {0};

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == (HANDLE)-1)
		return false;

	pe32.dwSize = sizeof(PROCESSENTRY32);
	DWORD dwProcessID = 0;

	if (Process32First(hProcessSnap, &pe32))
	{
		BOOL          bCurrent = FALSE;
		MODULEENTRY32 me32       = {0};
		do
		{
			bCurrent = GetProcessModule(pe32.th32ProcessID, pszProcessName);
			if(bCurrent)
			{
				dwProcessID = pe32.th32ProcessID;
				break;
			}

		} while (Process32Next(hProcessSnap, &pe32));
	}

	CloseHandle (hProcessSnap);
	return dwProcessID;
}

#include <psapi.h>

DWORD getProcessID(std::string pszProcessName)
{
	// get the list of process identifiers
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 0;
	}

	cProcesses = cbNeeded / sizeof(DWORD);

	bool bFound = false;
	DWORD processID = 0;
	for (size_t i = 0; i < cProcesses; i++)
	{
		processID = aProcesses[i];
		if (processID == 0)
		{
			continue;
		}

		TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

		// Get a handle to the process.
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, processID);

		// Get the process name.
		if (NULL != hProcess)
		{
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
				&cbNeeded))
			{
				GetModuleBaseName(hProcess, hMod, szProcessName,
					sizeof(szProcessName) / sizeof(TCHAR));
			}
		}

		// Print the process name and identifier.
		//printf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);

		char buf[MAX_PATH] = { 0 };
		strcpy_s(buf, MAX_PATH, szProcessName);

		if (buf == pszProcessName)
		{
			bFound = true;
		}

		// Release the handle to the process.
		CloseHandle(hProcess);

		if (bFound) {
			break;
		}
	}

	if (!bFound) {
		return 0;
	}

	return processID;
}

void readFromHWND(cv::Mat& img, const char *target)
{
	std::string name = "MEmu.exe";
	DWORD pid = getProcessID(name);

	HWND hwnd = GetWindowFromPID(pid);

	if (hwnd == NULL)
	{
		return;
		//return NULL;
	}

	HWND handle = FindWindowEx( hwnd, NULL, NULL, NULL);
	if (handle == NULL)
	{
		return;
		//return NULL;
	}
	
	HDC scDC = ::GetDC(GetDesktopWindow());
	HDC memDC = ::CreateCompatibleDC(scDC);

	RECT rc;
	GetWindowRect(handle, &rc);    

	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	BITMAPINFO dib_define;
	dib_define.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	dib_define.bmiHeader.biWidth = width;
	dib_define.bmiHeader.biHeight = height;
	dib_define.bmiHeader.biPlanes = 1;
	dib_define.bmiHeader.biBitCount = 24;
	dib_define.bmiHeader.biCompression = BI_RGB;
	dib_define.bmiHeader.biSizeImage = (((width * 24 + 31) & ~31) >> 3) * height;
	dib_define.bmiHeader.biXPelsPerMeter = 0;
	dib_define.bmiHeader.biYPelsPerMeter = 0;
	dib_define.bmiHeader.biClrImportant = 0;
	dib_define.bmiHeader.biClrUsed = 0;

	BYTE *p_image_data = NULL;

	HBITMAP h_bitmap = ::CreateDIBSection(scDC, &dib_define, DIB_RGB_COLORS, (void **)&p_image_data, 0, 0);
	HBITMAP h_old_bitmap = (HBITMAP)::SelectObject(memDC, h_bitmap);

	BitBlt(memDC, 0, 0, width, height, scDC, rc.left, rc.top, SRCCOPY);
	SelectObject(memDC, h_old_bitmap);

	DeleteDC(memDC);

	BITMAPFILEHEADER dib_format_layout;
	ZeroMemory(&dib_format_layout, sizeof(BITMAPFILEHEADER));
	dib_format_layout.bfType = *(WORD*)"BM";
	dib_format_layout.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dib_define.bmiHeader.biSizeImage;
	dib_format_layout.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	img = cv::Mat(cv::Size(width, height), IPL_DEPTH_8U, 3);
	memcpy(img.data, p_image_data, width * height);
	cv::flip(img, img, 0);
}


void readFromAdb(cv::Mat& img, const char *adb)
{
	string command = adb;
	command += "shell screencap -p > screen.png";

	system(command.c_str());

	FILE *fp = fopen("screen.png", "rb");
	FILE *fpout = fopen("tmp.png", "wb");

	const int buf_size = 65535;
	char buf[buf_size] = {0, };

	while (!feof(fp))
	{
		int sz = 0;
		int pos_prev = ftell(fp);

		if (fgets(buf, buf_size, fp) != NULL) {
			sz = ftell(fp) - pos_prev;

			char *pline = buf + sz - 3;
			if( strcmp(pline, "\r\r\n") == 0 ) {
				pline[0] = '\n';
				pline[1] = '\0';
				pline[2] = '\0';

				sz -= 2;
			}
		}

		fwrite(buf, sizeof(char), sz, fpout);

		memset(buf, 0x00, buf_size);
	}

	fclose(fp);
	fclose(fpout);

	img = cv::imread("tmp.png", -1);
}


void winapi::grab(cv::Mat& img)
{
	switch( _grabber ) {
	case api::WindowHandle:
		readFromHWND(img, adb().c_str());
		break;
	case api::Adb:
		readFromAdb(img, adb().c_str());
		break;
	}
};


std::string winapi::adb(bool flag)
{
	if (flag) {
		std::string ret = "adb -s " + _target;
		return ret;
	}
	else {
		return "adb ";
	}
}
