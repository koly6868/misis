add_executable(test_rational main.cpp)
target_link_libraries(test_rational rational)


set_property(TARGET complex PROPERTY CXX_STANDARD 14)
