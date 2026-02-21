cmake_minimum_required(VERSION 3.13)
project(BST C)

add_executable(bst main.c /task_A/bst.c /task_B/orders.c /taskC/BST_C.c)
target_compile_options(bst PUBLIC -Wall -Wextra -Wpedantic)