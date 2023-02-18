/*
 * File: misc.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 04.04.2022 22:30:35
 * Author: 3urobeat
 * 
 * Last Modified: 13.02.2023 21:39:43
 * Modified By: 3urobeat
 */

// Credit: https://github.com/seksea/gamesneeze/blob/master/src/utils/utils.hpp
// I'm currently not sure how this works completely

#pragma once


// TODO: Add function docs


inline uintptr_t getAbsoluteAddress(uintptr_t pointer, int offset, int size) {
	return pointer + *reinterpret_cast<int32_t *>(pointer + offset) + size;
}


inline void**& getVTable(void *c, size_t offset = 0) {
	return *reinterpret_cast<void ***>((size_t) c + offset);
}


template <typename T>
inline T getVirtualFunc(void *c, size_t i, size_t offset = 0) {
    return reinterpret_cast<T>(getVTable(c, offset)[i]);
}