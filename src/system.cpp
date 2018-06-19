#include "system.h"

System::System(const std::string& config_path)
{
	_config.loadConfig(config_path);
	_api = new winapi;

	bool bUseAdb = false;

	// set grab method
	if (_config.grabMethod == "adb") {
		bUseAdb = true;
		_api->setGrabMethod(api::Method::Adb);
	}
	else if (_config.grabMethod == "win_handle") {
		_api->setGrabMethod(api::Method::WindowHandle);
	}

	// set input method
	if (_config.inputMethod == "adb") {
		bUseAdb = true;
		_api->setInputMethod(api::Method::Adb);
	}
	else if (_config.inputMethod == "win_handle") {
		_api->setInputMethod(api::Method::WindowHandle);
	}

	// set app name
	_api->setAppName(_config.appInfo.window_title);

	if (bUseAdb)
	{
		if (_config.appInfo.name == "NoxPlayer")
		{
			system("adb connect 127.0.0.1:62001");
		}

		std::vector<std::string> targets = _api->getDevices();
		
		if (targets.size())
		{
			_api->setDevice(targets[0]);
		}
	}
}

System::~System()
{
	if (_api != NULL) {
		delete _api;
	}

	try {
		stop();
	}
	catch (...) {

	}
}

void System::start()
{
	_continue = true;
	_thread = std::thread(&System::loop, this);
}

void System::stop()
{
	_continue = false;
	_thread.join();
}

void System::loop()
{
	int i = 0;
	while (_continue)
	{
		printf("%d\n", i++);
		cv::Mat img;
		_api->grab(img);

		cv::imshow("test", img);
		cv::waitKey(0);

		//run_bot(img);
		//cvReleaseImage(&img);




	}
}


