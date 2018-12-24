
set(server_SRCS
    main.cpp
    server.cpp
    server.h
    client.h
    client.cpp
    configuration_manager.cpp
    configuration_manager.h
    console.h
    console.cpp
    file_systeam.h
    file_systeam.cpp
    enums.h
)

add_executable(server ${server_SRCS})

target_link_libraries(server Qt5::Widgets)
target_link_libraries(server Qt5::Network)