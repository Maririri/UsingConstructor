cmake_minimum_required(VERSION 3.8)
project(UsingConstructor)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "E:/Toolchains/cygwin2.3.1/usr/include")
set(BOOST_LIBRARYDIR "E:/Toolchains/cygwin2.3.1/lib")
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

find_package( Threads )

set(SOURCE_FILES main.cpp phil_example.cpp boost-cpp-5852.cpp cpp-3540.cpp cpp-9396.cpp cpp-9557.cpp related-cpp-9729.cpp related-cpp-2371.cpp related-cpp-7266.cpp related-cpp-3775.cpp)
add_executable(UsingConstructor ${SOURCE_FILES})
target_link_libraries(UsingConstructor ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})