#pragma once

#include <cstdint>

class Arena {
public:
	Arena() = default;
	Arena(size_t size);
	void* Alloc(size_t size);
	void Free();

private:
	uint8_t* data;
	size_t size;
	int32_t pos;
};