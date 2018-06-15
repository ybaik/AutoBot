#ifndef SYSTEM_H
#define SYSTEM_H

#include <thread>
#include <stdio.h>
#include <api/winapi.h>

class System
{
public:
	System();
	virtual ~System();

	void start();
	void stop();

private:
	void loop();

protected:
	std::thread _thread;

	bool _continue = false;
	api* _api;
};
#endif // SYSTEM_H