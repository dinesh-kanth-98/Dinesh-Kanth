 
# Project Compilation Readme

## Project Overview

This project enables communication between multiple clients through a central server. Clients can exchange messages with each other via a web page interface supported by the server.

## Compilation Instructions

### Step 1: Navigate to Build Folder

Navigate to the `build` folder of the project using the command line interface (CLI). If a `build` folder does not exist, create one.

```bash
cd /path/to/project/build
```

### Step 2: Clean Build Folder (Optional)

If the build folder contains any existing files from previous builds, it's recommended to clean them before compiling the project. Run the following command to remove all files and subdirectories:

```bash
rm -rf *
```

### Step 3: Run CMake

Once inside the `build` folder, run CMake to generate the necessary build files. CMake is a cross-platform build system generator. It reads CMakeLists.txt files in the project directory and generates build files accordingly.

```bash
cmake ..
```

### Step 4: Build the Project

After CMake has successfully generated the build files, you can proceed to build the project. Use one of the following commands based on your specific requirements:

- To build the entire project:

```bash
make all
```

- To build only the server component:

```bash
make server
```

- To build only the client component:

```bash
make client
```

Replace `server` and `client` with your actual component names if they differ.

### Step 5: Clean Up (Optional)

After the compilation is complete, you can clean up the build artifacts by running:

```bash
make clean
```

This command will remove all intermediate object files and binaries generated during the compilation process, leaving only the essential files required for running the project.

## Conclusion

Following the steps outlined in this readme should enable you to compile the project successfully. If you encounter any issues during the compilation process, please refer to the project documentation or seek assistance from project maintainers.