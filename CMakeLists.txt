cmake_minimum_required(VERSION 3.8.0)

project(fisk_win_utils)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)

Include(FetchContent)

FetchContent_Declare(
  fisk_tools
  GIT_REPOSITORY https://github.com/Fiskmans/fisk_tools.git
  GIT_TAG        144b8981c3beeb149d80964b76176e650d17db7f
)
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        29fadad1939ab62adcc5cd9339db7a784de90120
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
)

FetchContent_MakeAvailable(imgui)
FetchContent_MakeAvailable(fisk_tools)

add_subdirectory(imgui)
add_subdirectory(win_utils)
add_subdirectory(example)
