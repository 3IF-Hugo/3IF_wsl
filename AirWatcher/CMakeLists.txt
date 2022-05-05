cmake_minimum_required(VERSION 3.8)

set(This User)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    User.h
    PrivateUser.h
    Attribute.h
)

set(Sources
    User.cpp
    PrivateUser.cpp
    Attribute.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)

# cmake_minimum_required(VERSION 3.8)

# set(This Test)

# project(${This} C CXX)

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_CXX_STANDARD 11)

# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# enable_testing()

# add_subdirectory(googletest)

# set(Headers
#     Test.h
# )

# set(Sources
#     Test.cpp
# )

# add_library(${This} STATIC ${Sources} ${Headers})

# add_subdirectory(test)
