#pragma once
#include <map>
#include <vector>

#include "Listener.h"

class Platform {
public:
	static void Init();
	static bool Tick();
	static void Release();

	//P3
	static FILE* OpenFile(const char* name, const char* flags = "r");
	static void CloseFile(const char* name);
	static bool IsBigEndian();
	/*static void addInputListener(Observer* listener);
	static void removeInputListener(Observer* listener);*/
private:
	//P3
	static std::map<const char*, FILE*> _fileMap;
	/*static std::vector<Observer*> _inputListeners;

	static void notifyListeners(SDL_Event* evt);*/
};
