#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

struct AppPlayerInfo
{
	std::string name;
	std::string version;
	std::string window_title;
};

class Config
{
public:
	Config() {};
	~Config() {};

	// load configurations

	bool Config::loadConfig(const std::string& path);

	AppPlayerInfo appInfo;

	// grab and input
	std::string grabMethod;
	std::string inputMethod;

	

};

#endif //__CONFIG_H__