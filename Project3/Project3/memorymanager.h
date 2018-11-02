#ifndef D_MEMORYMANAGER_H
#define D_MEMORYMANAGER_H

#include <cstddef>

void memoryReport();

void* alloc(std::size_t sz, char const* file, char const*  func, int line);
void* operator new(std::size_t sz, char const* file, char const*  func, int line);
void* operator new[](std::size_t sz, char const* file, char const*  func, int line);

void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;

#endif
