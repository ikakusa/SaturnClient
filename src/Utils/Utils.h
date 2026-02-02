#pragma once
#include <Libraries.h>
#include "MathUtils.h"

#define u8str(name) reinterpret_cast<const char*>(std::u8string(name).data()), std::u8string(name).size())
namespace fs = std::filesystem;
class ClientData;
extern ClientData client;
class Utils {
public:
	static std::string getRoamingStatePath();
	static std::string getClientPath();
	static std::string formatString(const char* fmt, va_list args);
	static void outputDebugLog(const char* str, ...);

	static void makeFolder();

	static void makeAssetsFolder(std::string name);
};
#define logF(str, ...) Utils::outputDebugLog(str, __VA_ARGS__)