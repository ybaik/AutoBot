#include "winapi.h"

#include <string>
#include <windows.h>

using namespace std;

void readFromHWND(cv::Mat& img, const char *target)
{
	LPCTSTR windowName = "KOPLAYER 1.4.1055";
	HWND hwnd = FindWindow(NULL, windowName);

	if (hwnd == NULL)
	{
		printf("Can't find window\n");
		return;
	}

	RECT rc;
	GetWindowRect(hwnd, &rc);
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	HDC hScreenDC = GetWindowDC(hwnd);
	HDC hMemDC = CreateCompatibleDC(hScreenDC);
	HBITMAP hbmp = CreateCompatibleBitmap(hScreenDC, width, height);
	SelectObject(hMemDC, hbmp);
	BitBlt(hMemDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY);

	BITMAPINFO bmp_info = { 0 };
	bmp_info.bmiHeader.biSize = sizeof(bmp_info.bmiHeader);
	bmp_info.bmiHeader.biWidth = width;
	bmp_info.bmiHeader.biHeight = height;
	bmp_info.bmiHeader.biPlanes = 1;
	bmp_info.bmiHeader.biBitCount = 24;
	bmp_info.bmiHeader.biCompression = BI_RGB;

	int bmp_padding = (width * 3) % 4;
	if (bmp_padding != 0) bmp_padding = 4 - bmp_padding;

	BYTE *bmp_pixels = new BYTE[(width * 3 + bmp_padding) * height];;
	GetDIBits(hMemDC, hbmp, 0, height, bmp_pixels, &bmp_info, DIB_RGB_COLORS);

	// copy to cv::Mat
	img = cv::Mat(height, width, CV_8UC3, cv::Scalar(0));
	BYTE* src = bmp_pixels;
	BYTE* dst = img.data;

	for (int i = 0; i < height; i++)
	{
		memcpy(dst, src, img.step);
		src += img.step + bmp_padding;
		dst += img.step;
	}

	cv::flip(img, img, 0);
	
	delete[] bmp_pixels;
	DeleteDC(hMemDC);
	DeleteObject(hbmp);
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
