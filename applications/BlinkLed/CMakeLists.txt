cmake_minimum_required(VERSION 3.14)


# Program name
project (BlinkLed C CXX ASM)


# Deploy remotely
option(DEPLOYED_REMOTELY "Turn on for remote deployment" ON)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Set MCU library path
set(LIB_DIR "../../lib"
    CACHE PATH "The path to the MCU libraries.")

# Add MCU library to the compiler include directories
#include_directories("${LIB_DIR}/io"
#                    "${LIB_DIR}/component"
#                    "${LIB_DIR}/core"
#                    "${LIB_DIR}/utils")

# Add subdirectories to the build
#add_subdirectory("${LIB_DIR}/io" "${CMAKE_BINARY_DIR}/io")
#add_subdirectory("${LIB_DIR}/component" "${CMAKE_BINARY_DIR}/component")

# Set the internal and external libs
set (INTERN_LINK_LIBS ${INTERN_LINK_LIBS})
set (EXTERN_LINK_LIBS ${EXTERN_LINK_LIBS} -lpthread -lwiringPi crypt rt)

# Add an executable target
add_executable("${PROJECT_NAME}" main.cpp)

# Specify the libraries to use when linking the target
target_link_libraries("${PROJECT_NAME}" ${INTERN_LINK_LIBS} ${EXTERN_LINK_LIBS})

###################### Deploy section

file(WRITE "${CMAKE_BINARY_DIR}/QtCreatorDeployment.txt" "/home/pi\n")

macro(add_deployment_file SRC DEST)
    file(RELATIVE_PATH path ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
    file(APPEND "${CMAKE_BINARY_DIR}/QtCreatorDeployment.txt" "${path}/${SRC}:${DEST}\n")
endmacro()

macro(add_deployment_directory SRC DEST)
    file(GLOB_RECURSE files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${SRC}/*")
    foreach(filename ${files})
        get_filename_component(path ${filename} PATH)
        add_deployment_file("${filename}" "${DEST}/${path}")
    endforeach(filename)
endmacro()


add_deployment_file("${PROJECT_NAME}" applications)
