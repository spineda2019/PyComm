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

#ifndef SERIAL_SRC_INCLUDE_SERIALMESSENGER_HPP_
#define SERIAL_SRC_INCLUDE_SERIALMESSENGER_HPP_
#include <string_view>

#include "boost/asio/io_context.hpp"
#include "boost/asio/serial_port.hpp"
namespace sp {

class SerialMessenger {
 public:
    explicit SerialMessenger(const std::string_view port);

 private:
    boost::asio::io_context boost_context_;
    boost::asio::serial_port boost_port_;
};
}  // namespace sp

#endif  // SERIAL_SRC_INCLUDE_SERIALMESSENGER_HPP_
