#include <cstddef>
#include <cstdlib>

int simple_allocate() {
    size_t size = 1000000000;
    int* buffer = (int*) malloc(size*sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = i;
    }
    // do something with buffer
    free(buffer);
    return 0;
}