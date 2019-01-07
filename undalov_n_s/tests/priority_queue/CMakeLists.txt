add_executable(test_priority_queue main.cpp)
target_link_libraries(test_priority_queue priority_queue) 
set_property(TARGET priority_queue PROPERTY CXX_STANDARD 14)
