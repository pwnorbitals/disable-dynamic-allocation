#include <cstdlib>
#include <new>

extern void* (*disabled)();

void* operator new(std::size_t) {
    return disabled();
}

void* operator new[](std::size_t n) {
    return disabled();
}

void* operator new(std::size_t, std::nothrow_t const&){
    return disabled();
}

void* operator new[](std::size_t n, std::nothrow_t const&) {
    return disabled();
}

extern "C" {
    void* malloc(size_t size) {
        return disabled();
    }

    void free(void* ptr) {
        disabled();
    }

    void* calloc(size_t nmemb, size_t size) {
        return disabled();
    }

    void* realloc(void* ptr, size_t size) {
        return disabled();
    }
}