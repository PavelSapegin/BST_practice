cmake_minimum_required(VERSION 3.13)
project(BST C)

add_executable(bst
    ./src/main.c 
    ./src/task_A/bst.c 
    ./src/task_B/orders.c 
    ./src/task_C/BST_C.c 
    ./src/task_D/remove_el_from_bst.c 
    ./src/task_E/mergeTrees.c 
    ./src/task_F/checkCorrectness.c
    ./src/task_G/kthMin.c
    ./src/task_H/iterator.c
)

target_compile_options(bst PUBLIC -Wall -Wextra -Wpedantic)
