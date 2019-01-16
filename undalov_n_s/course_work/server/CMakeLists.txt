
set(server_SRCS
    main.cpp
    server.cpp
    server.h
    client_server.h
    client_server.cpp
    configuration_manager_server.cpp
    configuration_manager_server.h
)

add_executable(server ${server_SRCS})

target_link_libraries(server shared)
target_link_libraries(server Qt5::Core)
target_link_libraries(server Qt5::Network)