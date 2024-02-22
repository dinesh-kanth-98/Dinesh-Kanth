# cmake_minimum_required(VERSION 3.0)
# project(MyProject)

# # Include the common library
# #add_subdirectory(common)

# # Add subdirectories for server and client
# add_subdirectory(Server)
# add_subdirectory(Client)

# #add_executable(server ./Server/Source/server.c)

# #add_executable(client ./Client/Source/client.c)

#function(display_message MESSAGE_TEXT)
#  message(STATUS "${MESSAGE_TEXT}")
#endfunction()
#display_message("This is a custom message.")


# Define your project
project(MyProject)

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Define custom binary output paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_SERVER "${CMAKE_BINARY_DIR}/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_CLIENT "${CMAKE_BINARY_DIR}/")


# Find all source files in the Server/Source directory
file(GLOB_RECURSE SERVER_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/Server/Source/*.c"
    "/home/dinesh/Shared_Folder/Project/Common/include/*.c"
    "${CMAKE_SOURCE_DIR}/Common/Source/fileIO.c"
   # "/home/dinesh/Shared_Folder/Project/Common/include/debugs.c"
)

# Find all source files in the Client/Source directory
file(GLOB_RECURSE CLIENT_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/Client/Source/*.c"
    "/home/dinesh/Shared_Folder/Project/Common/include/*.c"
    # "/home/dinesh/Shared_Folder/Project/Common/include/file_mime_type.c"
    # "/home/dinesh/Shared_Folder/Project/Common/include/debugs.c"
    # "/home/dinesh/Shared_Folder/Project/Client/Source/Login_verify.h"
)

# Find all header files in the Common/include directory
#file(GLOB_RECURSE common_header_files
#    "${CMAKE_SOURCE_DIR}/Common/include/*.h"
#)
#message("${common_header_files}")

# Add the Server and Client executables
add_executable(Server ${SERVER_SOURCE_FILES})   # ${common_header_files})
add_executable(Client ${CLIENT_SOURCE_FILES})   # ${common_header_files})


# Specify the include directories
 target_include_directories(Server PRIVATE
     "${CMAKE_SOURCE_DIR}/Common/include/"
     "${CMAKE_SOURCE_DIR}/Server/Source/"
     "${CMAKE_SOURCE_DIR}/Common/Source/"

 )
 target_include_directories(Client PRIVATE
     "${CMAKE_SOURCE_DIR}/Common/include/"
     "${CMAKE_SOURCE_DIR}/Client/Source/"
     "/home/dinesh/Shared_Folder/Project/Client/Source/"
 )

# Set the binary output path for Server
set_target_properties(Server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_SERVER}"
)
# Set the binary output path for Client
set_target_properties(Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_CLIENT}"
)

# Link the pthread library to both Server and Client
target_link_libraries(Server PRIVATE pthread)
target_link_libraries(Client PRIVATE pthread)
target_link_libraries(Server PRIVATE jansson)
target_link_libraries(Client PRIVATE jansson)

# Set compile options for both Server and Client
target_compile_options(Server PRIVATE -Wall -Wextra ) # -Werror
target_compile_options(Client PRIVATE -Wall -Wextra ) #-Werror

