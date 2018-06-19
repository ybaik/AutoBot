#include "api.h"

#ifdef _WIN32
#define POPEN(x, y)	_popen(x, y)
#define PCLOSE(x)	_pclose(x)
#else
#define POPEN(x, y)	popen(x, y)
#define PCLOSE(x)	pclose(x)
#endif

api::api()
{

}

api::Method api::getGrabMethod()
{
	return _grab_method;
}

void api::setGrabMethod(Method grabber)
{
	_grab_method = grabber;
}

void api::setInputMethod(Method input)
{
	_input_method = input;
}

void api::setAppName(const std::string& app_name)
{
	_appName = app_name;
}

std::vector<std::string> api::getDevices()
{
	std::vector<std::string> ret = std::vector<std::string>();

	std::string command = adb(false);
	command += "devices";

	FILE* fp = POPEN(command.c_str(), "r");

	if (fp != NULL) {

		char buf[1024];
		int idx = 0;
		while (fgets(buf, 1024, fp) != NULL) {
			idx++;
			if (idx == 1) continue;
			if (strcmp("\n", buf) == 0) continue;

			std::string line = buf;
			int pos = line.find_first_of("\t");

			ret.push_back(line.substr(0, pos));
		}
		PCLOSE(fp);
	}

	return ret;
}

void api::setDevice(std::string did)
{
	_target = did;
}

