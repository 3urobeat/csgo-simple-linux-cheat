//Used from here for now: https://github.com/seksea/gamesneeze/blob/15f087eb882d5d5b8a1b333ab249cdb7fa17098b/src/utils/utils.hpp
//TODO: Make myself

inline uintptr_t getAbsoluteAddress(uintptr_t ptr, int offset, int size) {
	return ptr + *reinterpret_cast<int32_t*>(ptr + offset) + size;
}

inline void**& getVTable(void* c, size_t offset = 0) {
	return *reinterpret_cast<void***>((size_t)c + offset);
}

template <typename T>
inline T getVirtualFunc(void* c, size_t i, size_t offset = 0) {
    return reinterpret_cast<T>(getVTable(c, offset)[i]);
}