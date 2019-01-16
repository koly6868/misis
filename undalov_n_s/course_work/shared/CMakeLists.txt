add_library(shared 
	console.cpp 
	console.h 
	enums.h
	file_systeam.cpp
	file_systeam.h)
target_link_libraries(shared Qt5::Core)
set_property(TARGET shared PROPERTY CXX_STANDARD 14)
