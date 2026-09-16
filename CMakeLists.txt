#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME LF_STM32)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM, C and C++ languages
enable_language(C ASM CXX)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    Core/Src/lsm6dsr_reg.c
    Robot/robot.cpp

    # Context
    Robot/Context/GlobalData.cpp

    # Drivers
    Robot/Drivers/Encoders/Encoders.cpp
    Robot/Drivers/IMU/IMU.cpp
    Robot/Drivers/IRSensors/IRSensors.cpp
    Robot/Drivers/Leds/Leds.cpp
    Robot/Drivers/Motors/Motors.cpp
    Robot/Drivers/Vacuum/Vacuum.cpp

    # Services
    Robot/Services/BLE/BLE.cpp
    Robot/Services/Mapper/Mapper.cpp
    Robot/Services/PID/PID.cpp

    # Utils
    Robot/Utils/Battery/Battery.cpp
    Robot/Utils/DataManager/DataManager.c
    Robot/Utils/ErrorHandler/ErrorHandler.cpp
    Robot/Utils/LaboratoryTesting/LaboratoryTesting.cpp
    Robot/Utils/Logger/Logger.cpp
    Robot/Utils/Timer/Timer.cpp
    Robot/Utils/Timestamp/Timestamp.cpp
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
    # Standard libraries
    c
    m
    stdc++
    supc++
)

# Add linker options
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    # Enable floating-point support in printf
    "-Wl,-u,_printf_float"
    # Enable floating-point support in scanf
    "-Wl,-u,_scanf_float"
)

# Add compile options
add_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    # Enable warnings and errors
    -Wall
    -Wextra
    -Wunused
    -Werror=implicit-function-declaration
    -Werror=address
    -Werror=array-bounds
    -Werror=empty-body
    -Werror=implicit
    -Werror=incompatible-pointer-types
    -Werror=init-self
    -Werror=int-conversion
    -Werror=int-to-pointer-cast
    -Werror=main
    -Werror=misleading-indentation
    -Werror=missing-braces
    -Werror=missing-include-dirs
    -Werror=nonnull
    -Werror=overflow
    -Werror=parentheses
    -Werror=pointer-arith
    -Werror=pointer-to-int-cast
    -Werror=return-type
    -Werror=sequence-point
    -Werror=shadow
    -Werror=trigraphs
    -Werror=undef
    -Werror=write-strings
    -Wformat-nonliteral
    -Wignored-qualifiers
    -Wimplicit-function-declaration
    -Wlogical-op
    -Wmissing-format-attribute
    -Wmissing-include-dirs
    -Wno-cast-function-type
    -Wno-dangling-pointer
    -Wno-missing-field-initializers
    -Wno-sign-compare
    -Wno-unused-parameter
    -Wpointer-arith
    -Wswitch-default
    -Wundef
    -Wuninitialized
)

# Add language specific options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:ASM>:-mthumb>

    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
)
