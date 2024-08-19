
list(APPEND files "${imgui_SOURCE_DIR}/imconfig.h")
list(APPEND files "${imgui_SOURCE_DIR}/imgui.h" "${imgui_SOURCE_DIR}/imgui.cpp")
list(APPEND files "${imgui_SOURCE_DIR}/imgui_demo.cpp")
list(APPEND files "${imgui_SOURCE_DIR}/imgui_draw.cpp")
list(APPEND files "${imgui_SOURCE_DIR}/imgui_internal.h")
list(APPEND files "${imgui_SOURCE_DIR}/imgui_tables.cpp")
list(APPEND files "${imgui_SOURCE_DIR}/imgui_widgets.cpp")
list(APPEND files "${imgui_SOURCE_DIR}/imstb_rectpack.h")
list(APPEND files "${imgui_SOURCE_DIR}/imstb_textedit.h")
list(APPEND files "${imgui_SOURCE_DIR}/imstb_truetype.h")
list(APPEND files "imgui_tree.h")

list(APPEND files "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.h" "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp")

if (WIN32)
list(APPEND files "${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp" "${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.h")
list(APPEND files "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp" "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.h")
endif()

add_library(fisk_imgui ${files})

target_include_directories(fisk_imgui PUBLIC ${imgui_SOURCE_DIR})
target_include_directories(fisk_imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
