# # Define your project
# project(Client)

# # Find all source files in the Server/Source directory
# file(GLOB_RECURSE Client_source_files
#     "${CMAKE_SOURCE_DIR}/Client/Source/*.c"
# )

# file(GLOB_RECURSE client_header_files
#     "${CMAKE_SOURCE_DIR}/Common/include/*.h"
# )

# # Add the server executable
# add_executable(Client ${Client_source_files} ${client_header_files})

# # Specify the include directories for the Server target
# # target_include_directories(Server PRIVATE
# #     ${server_header_files}  # Add the Common/include directory
# # )

# # Link the pthread library to the Server target
# target_link_libraries(Client PRIVATE pthread)

# # Set compile options for the Server target
# target_compile_options(Client PRIVATE -Wall -Wextra -Werror)
