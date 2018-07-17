#ifndef SYSTEM_H
#define SYSTEM_H

#include <thread>
#include <stdio.h>
#include <api/winapi.h>
#include <config/config.h>

class System
{
public:
	System(const std::string& config_path);
	virtual ~System();

	void start();
	void stop();

	api::Method getGrabMethod() { return _api->getGrabMethod();};
	void setGrabMethod(api::Method grab) { _api->setGrabMethod(grab); };

private:
	void loop();

protected:
	std::thread _thread;

	bool _continue = false;

	Config _config;
	api* _api;
};
#endif // SYSTEM_H