#include "system.hpp"

System::System()
{
	_api = new winapi;
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


