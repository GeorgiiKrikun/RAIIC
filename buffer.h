#pragma once
#include <cstdlib>
#include <iostream>

class buffer_simple
{
public:
    buffer_simple() {
        data = (int*) malloc(size * sizeof(int));
    }
    ~buffer_simple() {
        free(data);
    }

    void fill() {
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
    }

private:
    int* data;
    const int size = 1000000000;
};

class BetterBuffer 
{
public:
    BetterBuffer() {
        std::cout << "BetterBuffer constructor" << std::endl;
        data = (int*) malloc(size * sizeof(int));
    }
    ~BetterBuffer() {
        if (data) {
            free(data);
        }
    }

    BetterBuffer(const BetterBuffer & another) {
        std::cout << "BetterBuffer copy constructor" << std::endl;
        data = (int*) malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
        {
            data[i] = another.data[i];
        }
    }


    void fill() {
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
    }

private:
    int* data;
    const int size = 1000000000;
};


class MoveBuffer 
{
public:
    MoveBuffer() {
        std::cout << "BetterBuffer constructor" << std::endl;
        data = (int*) malloc(size * sizeof(int));
    }
    ~MoveBuffer() {
        if (data) {
            free(data);
        }
    }

    // Explicitly delete copy constructor
    MoveBuffer(const MoveBuffer & another) = delete;

    // Explicitly delete copy assignment operator
    // Instead of copy constructor, somebody might circumvent it by using copy assignment operator
    // E.g. MoveBuffer mb1;
    // std::vector<MoveBuffer> buffers;
    // buffers.push_back(MoveBuffer());
    // buffers[0] = mb1;
    MoveBuffer& operator=(const MoveBuffer & another) = delete;

    // Move constructor
    MoveBuffer(MoveBuffer && another) {
        std::cout << "MoveBuffer move constructor" << std::endl;
        data = another.data;
        another.data = nullptr;
    }

    // Move assignment operator
    MoveBuffer& operator=(MoveBuffer && another) {
        std::cout << "MoveBuffer move assignment operator" << std::endl;
        if (this != &another) {
            if (data) {
                free(data);
            }
            data = another.data;
            another.data = nullptr;
        }
        return *this;
    }

    void fill() {
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
    }

private:
    int* data;
    const int size = 1000000000;
};

