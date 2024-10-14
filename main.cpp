#include <iostream>
#include "buffer.h"
#include "simple_allocate.h"
#include "allocate_exception.h"
#include "RAII_exception.h"

int main() {
    // simple_allocate();
    try {
        // allocate_exception();
        // RAII_exception();
        // RAII_double_free();
        // better_buffer_no_exception();
        move_buffer_exception();
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;    
    
}