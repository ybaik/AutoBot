#include "api.hpp"

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

api::Grabber api::getGrabber()
{
	return _grabber;
}

void api::setGrabber(Grabber grabber)
{
	_grabber = grabber;
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

