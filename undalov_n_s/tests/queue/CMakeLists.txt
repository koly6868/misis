add_executable(test_queue main.cpp)
target_link_libraries(test_queue queue)
set_property(TARGET complex PROPERTY CXX_STANDARD 14)
