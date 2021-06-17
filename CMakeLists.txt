cmake_minimum_required(VERSION 3.19)
project(tv_pricer)


set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        nana
        GIT_REPOSITORY https://github.com/cnjinhao/nana.git
        GIT_TAG        develop-1.8
)

FetchContent_GetProperties(nana)
if(NOT nana_POPULATED)
    FetchContent_Populate(nana)
    add_subdirectory(${nana_SOURCE_DIR} ${nana_BINARY_DIR})
endif()

add_executable(tv_pricer main.cpp calculations.cpp calculations.h gui_helper.cpp gui_helper.h)

target_link_libraries(tv_pricer
        nana
        )