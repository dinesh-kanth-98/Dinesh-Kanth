# # Define your project
# project(Server)

# # Find all source files in the Server/Source directory
# file(GLOB_RECURSE
#     server_source_files
#     "${CMAKE_SOURCE_DIR}/Server/Source/*.c"
# )

# file(GLOB_RECURSE
#     server_header_files
#     "${CMAKE_SOURCE_DIR}/Common/include/*.h"
# )

# # Add the server executable
# add_executable(Server ${server_source_files} ${server_header_files})

# # Specify the include directories for the Server target
# # target_include_directories(Server PRIVATE
# #     ${server_header_files}  # Add the Common/include directory
# # )

# # Link the pthread library to the Server target
# target_link_libraries(Server PRIVATE pthread)

# # Set compile options for the Server target
# target_compile_options(Server PRIVATE -Wall -Wextra -Werror)
