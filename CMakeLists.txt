cmake_minimum_required(VERSION 3.25)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "")  # provide a json file with the compile commands so clangd can use it

project(VTSite LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# Include the fetch content submodule and use it to fetch the dependencies
include(FetchContent)


# Disable the SDL_Image backends
foreach(loader AVIF BMP GIF LBM PCX PNM QOI SVG TGA TIF XCF XPM XV STB)
    set(SDLIMAGE_${loader} OFF CACHE BOOL "" FORCE)
endforeach()


set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)

# Fetch the dependencies
FetchContent_Declare(SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-3.2.26
)

FetchContent_MakeAvailable(SDL3)


FetchContent_Declare(SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG        release-3.2.4
)
FetchContent_MakeAvailable(SDL3_image)


FetchContent_Declare(SDL3_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG        release-3.2.0
)

set(SDLTTF_VENDORED ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SDL3_ttf)

add_executable(VTSite src/main.cpp src/app_context.cpp 
src/event.cpp src/gui_label.cpp src/gui_button.cpp src/loop.cpp src/element_init.cpp)


target_include_directories(VTSite PRIVATE src src/include)

target_link_libraries(VTSite PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)

if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")

    target_link_options(VTSite PRIVATE
        "-sALLOW_MEMORY_GROWTH"               
        "--preload-file" "${CMAKE_SOURCE_DIR}/app_data/assets@assets"
        "--shell-file" "${CMAKE_SOURCE_DIR}/app_data/shell.html"
    )
endif()