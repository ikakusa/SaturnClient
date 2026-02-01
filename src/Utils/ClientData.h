#pragma once
#include <Libraries.h>

class ClientData {
private:
	static inline std::string ClientName = "McDonalds";
public:
	static std::string getName() {
		return ClientName;
	}
};

extern ClientData client;