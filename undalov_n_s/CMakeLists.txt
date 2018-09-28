cmake_minimum_required(VERSION 3.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")


project(undalov_n_s)


include(cmake/build_prefix.cmake)


add_subdirectory(prj.labs)