add_executable(test_complex main.cpp)

target_link_libraries(test_complex complex)
set_property(TARGET complex PROPERTY CXX_STANDARD 14)

