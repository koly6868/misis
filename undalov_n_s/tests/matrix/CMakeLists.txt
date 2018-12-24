add_executable(test_matrix main.cpp)
target_link_libraries(test_matrix matrix) 
set_property(TARGET matrix PROPERTY CXX_STANDARD 14)
