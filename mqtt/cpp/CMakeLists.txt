cmake_minimum_required(VERSION 3.7.0)
project(riks-samples-mqtt-client)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mqtt_client.cpp
    src/riks_mqtt_client.cpp)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/libriks.so
        Threads::Threads
        OpenSSL::SSL
        OpenSSL::Crypto
        Boost::system)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
        ${Boost_INCLUDE_DIRS})