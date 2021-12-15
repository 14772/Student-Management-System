cmake_minimum_required(VERSION 3.20)
project(Student_Performance_Management_System)

set(CMAKE_C_STANDARD 99)

add_executable(Student_Performance_Management_System main.cpp insert_item.cpp init_list.cpp destroy_list.cpp destroy_list_and_file.cpp delete_item.cpp change_item.cpp bubble_sort.cpp output_all_items.cpp output_one_item.cpp read_info.cpp save_to_file.cpp search_item.cpp Student_Performance_Management_System.h input_login.cpp create_file.cpp read_grades_info.cpp read_class_info.cpp judge_button.cpp)

target_link_libraries(Student_Performance_Management_System libEasyX.a libgdi32.a libole32.a)
