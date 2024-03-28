#include "SerialMessenger.hpp"

int main() {
    sp::SerialMessenger messenger("/dev/ttyS1");
    return 0;
}
