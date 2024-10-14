#include "buffer.h"
#include <exception>
#include <vector>

int RAII_exception() {
    buffer_simple RAII_buffer;
    RAII_buffer.fill();
    throw std::exception();
    return 0;
}

int RAII_double_free() {
    buffer_simple RAII_buffer;
    std::vector<buffer_simple> buffers;
    buffers.push_back(RAII_buffer);

    return 0;
}

int better_buffer_no_exception() {
    BetterBuffer bb;
    bb.fill();
    std::vector<BetterBuffer> buffers;
    buffers.push_back(bb);
    return 0;
}

int move_buffer_exception() {
    MoveBuffer mb;
    mb.fill();
    std::vector<MoveBuffer> buffers;
    buffers.push_back(std::move(mb)); // This will cause a compilation error
    return 0;
}