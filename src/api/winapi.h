#ifndef __WIN_API_H__
#define __WIN_API_H__

#include "api.hpp"

class winapi : public api
{
public:
	virtual std::string adb(bool flag=true);
	virtual void grab(cv::Mat& img);
};

#endif