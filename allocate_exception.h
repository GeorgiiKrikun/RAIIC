#include <cstddef>
#include <cstdlib>
#include <exception>

int allocate_exception() {
    size_t size = 1000000000;
    int* buffer = (int*) malloc(size*sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = i;
    }

    throw std::exception();

    free(buffer);
    return 0;
}