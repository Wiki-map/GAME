#include "utils/arena.hpp"
#include <cstdlib>
#include <print>

Arena::Arena(size_t size) {
	data = (uint8_t*) malloc(size);
	this->size = size;
	pos = 0;
}

void* Arena::Alloc(size_t size) {
	if (pos + size > this->size) {
		std::println("ERROR: Arena alloc overflow");
		return nullptr;
	}
	uint8_t* rez = &this->data[pos];
	pos += size;

	return (void*)rez;
}

void Arena::Free() {
	size = 0;
	pos = 0;
	free(data);
}
