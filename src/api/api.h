#ifndef __API_H__
#define __API_H__

#include <string>
#include <vector>
#include <opencv/cv.h>
#include <opencv/highgui.h>

class api
{
public:
	enum Method {
		WindowHandle,
		Adb
	};

public:
	api();
	virtual ~api() {};

	Method getGrabMethod();
	void setGrabMethod(Method grab);
	void setInputMethod(Method input);
	void setAppName(const std::string& app_name);

	std::vector<std::string> getDevices();
	void setDevice(std::string deviceID);

	virtual void grab(cv::Mat& img) = 0;


protected:
	virtual std::string adb(bool flag = true) = 0;


protected:
	Method _grab_method;
	Method _input_method;

	std::string _appName; // for WindowHandle

	std::string _target = "";

};

#endif //__API_H__