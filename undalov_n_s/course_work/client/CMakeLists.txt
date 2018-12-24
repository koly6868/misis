
set(client_SRCS
	main.cpp
	configuration_manager.h
	configuration_manager.cpp
	client.h
	client.cpp
	console.h
	console.cpp
	enums.h
	file_systeam.h
	file_systeam.cpp
	client_controller.cpp
	client_controller.h
	interface.h
	interface.cpp)

add_executable(client ${client_SRCS})
target_link_libraries(client Qt5::Widgets)
target_link_libraries(client Qt5::Network)
include_directories(/dll)