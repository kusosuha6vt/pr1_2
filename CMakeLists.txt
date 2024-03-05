cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(pr1_2)

include_directories(include)

set(ifiles
    include/data.h
    include/list_deque.h
    include/simple_vector_deque.h
    include/vector_deque.h
    include/menu.h
)

set(sfiles
    src/list_deque.cpp
    src/simple_vector_deque.cpp
    src/vector_deque.cpp
    src/menu.cpp
)

add_executable(pr1_2
    "${ifiles}"
    "${sfiles}"
    src/main.cpp    
)

# add_executable(test
#     "${ifiles}"
#     "${sfiles}"
#     src/test.cpp    
# )
