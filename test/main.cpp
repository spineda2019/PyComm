/*
 *  Copyright 2024 Sebastian Pineda (spineda.wpi.alum@gmail.com)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

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
