#ifndef __WIN_API_H__
#define __WIN_API_H__

#include "api.hpp"

class winapi : public api
{
public:
	virtual std::string adb(bool flag=true);
	virtual void grab(cv::Mat& img);
	
protected:
	static BOOL EnumWindowsProc(HWND hwnd, LPARAM lParam);
	void readFromHWND(cv::Mat& img, const char *target);

	char *title = "Notepad++";
};

#endif