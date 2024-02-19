# Project README

## Project Structure

The project is organized with the following directory structure:

```shell

project_directory/
│
├── WebServer/
│   ├── Webserver.c
│   ├── Webserver.h
│
├── Settings/
│   ├── Settings.c
│   ├── Settings.h
│
├── CommonInclude/
│   ├── CommonInclude.h
│
├── obj/
└── bin/

```

- `WebServer`: Contains source files (`web1.c` and `web2.c`) and header files (`web1.h` and `web2.h`) related to the Web Server module.
- `Settings`: Contains source files (`settings1.c` and `settings2.c`) and header files (`settings1.h` and `settings2.h`) related to the Settings module.
- `CommonInclude`: Contains common header files (`common1.h` and `common2.h`) shared across modules.
- `obj`: Directory for storing object files during compilation.
- `bin`: Directory for storing the final executable binary.

## Compilation Process

The project uses a Makefile for compilation. To build the executable `webApiServer`, follow these steps:

1. Open a terminal and navigate to the project directory.

2. Run the following command to compile the project:

   ```bash
   make
   ```

   This command will compile the source files, create object files, and link them to generate the `webApiServer` binary in the `bin` directory.

3. To clean the project and remove generated files, run:

   ```bash
   make clean
   ```

   This command will remove the `obj` and `bin` directories, as well as the `webApiServer` binary.

Note: Ensure that you have the necessary dependencies and a working GCC compiler installed on your system.

Make sure to customize the information based on the specifics of your project and any additional details you'd like to provide in the `README.md` file.
