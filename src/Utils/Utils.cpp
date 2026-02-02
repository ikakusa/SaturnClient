#include "Utils.h"
#include "ClientData.h"
#include <direct.h>

std::string Utils::getRoamingStatePath() {
    char* value = nullptr;
    size_t size = 0;
    _dupenv_s(&value, &size, "AppData");
    std::string path = std::string(value) + "\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\";
    free(value);
    return path;
}

std::string Utils::getClientPath() {
    return getRoamingStatePath() + client.getName();
}

std::string Utils::formatString(const char* fmt, va_list args) {
    int lengthNeeded = _vscprintf(fmt, args) + 1;
    if (lengthNeeded <= 1 || lengthNeeded >= 500) return "";
    char message[500];
    vsnprintf_s(message, sizeof(message), _TRUNCATE, fmt, args);
    return std::string(message);
}

void Utils::outputDebugLog(const char* str, ...) {
    va_list arg;
    va_start(arg, str);
    std::string msg = formatString(str, arg);
    va_end(arg);

    msg += "\n";
    std::string path = getClientPath() + "\\Logs\\logs.txt";
    std::ofstream ofs(path, std::ios::app);
    if (ofs.is_open()) { ofs << msg; ofs.close(); }
    OutputDebugStringA(msg.c_str());
}

void Utils::makeFolder() { _mkdir(getClientPath().c_str()); }
void Utils::makeAssetsFolder(std::string name) { _mkdir((getClientPath() + "\\" + name).c_str()); }