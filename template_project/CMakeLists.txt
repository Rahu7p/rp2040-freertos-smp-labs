# ============================================================================
# RP2040 FreeRTOS SMP Template Project
#
# Target Platform:
#   - Raspberry Pi RP2040
#   - FreeRTOS SMP
#
# This project is intended to serve as the starting point for all laboratory
# activities in this manual.
#
# ============================================================================
cmake_minimum_required(VERSION 3.13)

# ----------------------------------------------------------------------------
# Language Configuration
# ----------------------------------------------------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------------
# Raspberry Pi Pico VSCode Extension
# DO NOT MODIFY THIS SECTION
# ----------------------------------------------------------------------------
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)

set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if(EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# ----------------------------------------------------------------------------
# Target Board
# ----------------------------------------------------------------------------
set(PICO_BOARD pico CACHE STRING "Board type")

# ----------------------------------------------------------------------------
# Import Pico SDK
# ----------------------------------------------------------------------------
include(pico_sdk_import.cmake)

# ----------------------------------------------------------------------------
# Project Name
# Rename this project when creating a new laboratory.
# ----------------------------------------------------------------------------
project(template_project C CXX ASM)

# ----------------------------------------------------------------------------
# Initialize Pico SDK
# ----------------------------------------------------------------------------
pico_sdk_init()

# ----------------------------------------------------------------------------
# FreeRTOS Configuration
# ----------------------------------------------------------------------------
set(FREERTOS_PORT GCC_RP2040 CACHE STRING "")
set(FREERTOS_HEAP 4 CACHE STRING "")

include(
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake
)

# ----------------------------------------------------------------------------
# FreeRTOS Configuration Header
# ----------------------------------------------------------------------------
add_library(freertos_config INTERFACE)

target_include_directories(freertos_config
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/config
)

# ----------------------------------------------------------------------------
# Application Sources
# ----------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
    src/main.c

    # Additional application source files
)

# ----------------------------------------------------------------------------
# Include Directories
# ----------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/config
        ${CMAKE_CURRENT_LIST_DIR}/include
        
        # Add additional include directories here
)

# ----------------------------------------------------------------------------
# Libraries
# ----------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

# ----------------------------------------------------------------------------
# USB / UART Configuration
# ----------------------------------------------------------------------------
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# ----------------------------------------------------------------------------
# Output Files
# ----------------------------------------------------------------------------
pico_set_program_name(${PROJECT_NAME} "${PROJECT_NAME}")
pico_set_program_version(${PROJECT_NAME} "1.0")
pico_add_extra_outputs(${PROJECT_NAME})
