#include <iostream>
#include <ostream>

#include "SerialMessenger.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Use: test <COM PORT>" << std::endl;
        return -1;
    }

    std::cout << "Port Requested: " << argv[1] << std::endl;

    sp::SerialMessenger messenger(argv[1]);
    return 0;
}
