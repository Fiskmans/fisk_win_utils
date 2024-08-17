list(APPEND files main.cpp)

add_executable(win_utils_example "${files}")

target_link_libraries(win_utils_example PUBLIC fisk_win_utils)