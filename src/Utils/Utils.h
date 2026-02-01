#pragma once
#include <Libraries.h>
#include "ClientData.h"

#define u8str(name) reinterpret_cast<const char*>(std::u8string(name).data()), std::u8string(name).size())
namespace fs = std::filesystem;
class Utils {
public:
	static std::string getRoamingStatePath()
	{
		char* value;
		size_t size;
		_dupenv_s(&value, &size, "AppData");

		std::string roamingPathCStr = value + (std::string)"\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\";
		free(value);
		return roamingPathCStr;
	}
	static std::string getClientPath() {
		return getRoamingStatePath() + client.getName();
	}
	static void outputDebugLog(const char* str, ...) {
		va_list arg;
		va_start(arg, str);
		int lengthNeeded = _vscprintf(str, arg) + 1;
		if (lengthNeeded >= 300) {
			va_end(arg);
			return;
		}
		char message[300];
		vsnprintf_s(message, sizeof(message), _TRUNCATE, str, arg);
		std::string msg(message);
		msg += "\n";
		OutputDebugStringA(msg.c_str());
		va_end(arg);
	}
#define logF(str, ...) outputDebugLog(xorstr_(str), __VA_ARGS__)

	static void makeFolder() {
		std::string path = Utils::getRoamingStatePath() + client.getName();
		_mkdir(path.c_str());
	}

	static inline void makeAssetsFolder(std::string name) {
		std::string path = getClientPath() + name;
		_mkdir(path.c_str());
	}
};