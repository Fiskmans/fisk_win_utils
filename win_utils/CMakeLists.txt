
list(APPEND files ComObject.h)

list(APPEND files GraphicsFramework.h GraphicsFramework.cpp)
list(APPEND files ImguiHelper.h ImguiHelper.cpp)
list(APPEND files Window.h Window.cpp)


add_library(fisk_win_utils "${files}")

target_include_directories(fisk_win_utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")

target_link_libraries(fisk_win_utils PUBLIC fisk_tools)
target_link_libraries(fisk_win_utils PUBLIC fisk_imgui)
target_link_libraries(fisk_win_utils PUBLIC d3d11.lib)