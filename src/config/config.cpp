#include "config.h"
#include "../tinyxml/tinyxml.h"

bool Config::loadConfig(const std::string& path)
{
	TiXmlDocument doc, doc_dst;
	if (doc.LoadFile(path.c_str(), TIXML_ENCODING_UTF8) == false)
	{
		printf("Config file loading fail.\n");
		return false;
	}

	TiXmlElement* root = doc.FirstChildElement("Config");
	if (!root) return false;

	// app player information
	TiXmlElement* app_player = root->FirstChildElement("AppPlayer");
	appInfo.name		 = std::string(app_player->Attribute("name"));
	appInfo.version		 = std::string(app_player->Attribute("version"));
	appInfo.window_title = std::string(app_player->Attribute("window_title"));

	// api information
	TiXmlElement* api = root->FirstChildElement("API");
	grabMethod = std::string(api->Attribute("grab_method"));
	inputMethod = std::string(api->Attribute("input_method"));

	return true;
}