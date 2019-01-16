
set(client_SRCS
	main.cpp
	client.h
	client.cpp
	client_controller.cpp
	client_controller.h
	interface.h
	interface.cpp
	configuration_manager.h
	configuration_manager.cpp)

add_executable(client ${client_SRCS})
target_link_libraries(client shared)
target_link_libraries(client Qt5::Core)
target_link_libraries(client Qt5::Network)

