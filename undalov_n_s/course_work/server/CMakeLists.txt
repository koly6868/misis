
set(server_SRCS
    main.cpp
    server.cpp
    server.h
    client.h
    client.cpp
    configuration_manager.cpp
    configuration_manager.h
)

add_executable(server ${server_SRCS})

target_link_libraries(server shared)
target_link_libraries(server Qt5::Core)
target_link_libraries(server Qt5::Network)