#ifndef __API_H__
#define __API_H__

#include <string>
#include <vector>
#include <opencv/cv.h>
#include <opencv/highgui.h>

class api
{
public:
	enum Grabber {
		WindowHandle,
		Adb
	};

public:
	api();
	virtual ~api() {};

	Grabber getGrabber();
	void setGrabber(Grabber grab);

	std::vector<std::string> getDevices();
	void setDevice(std::string deviceID);

	virtual void grab(cv::Mat& img) = 0;


protected:
	virtual std::string adb(bool flag = true) = 0;


protected:
	Grabber _grabber = Grabber::WindowHandle;
	std::string _target = "";

};

#endif //__API_H__