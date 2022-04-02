//I did not create this file. Source: https://github.com/seksea/gamesneeze/blob/7ec40e08a9964549672da6c735567ff613262097/src/sdk/interfaces/ivengineclient.hpp

#include <string.h>

inline void**& getVTable(void* c, size_t offset = 0) {
	return *reinterpret_cast<void***>((size_t)c + offset);
}

template <typename T>
inline T getVirtualFunc(void* c, size_t i, size_t offset = 0) {
    return reinterpret_cast<T>(getVTable(c, offset)[i]);
}


class IVEngineClient {
public:
    // Gets the dimensions of the game window
	void GetScreenSize(int& width, int& height) {
		typedef void (*Fn)(void*, int&, int&);
		return getVirtualFunc<Fn>(this, 5)(this, width, height);
	}
};