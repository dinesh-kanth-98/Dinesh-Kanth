#!/bin/bash

# Function to display help information
display_help() {
    echo "Usage: myutility [OPTION]"
    echo "Options:"
    echo "  -h, --help        Display this help message"
    echo "  -c, --cpu         Display CPU information"
    echo "  -k, --kernel      Display kernel information"
    echo "  -m, --free-memory Display free memory"
    echo "  -s, --system-info Display system information"
}

# Function to display CPU information
display_cpu_info() {
    echo "CPU Information:"
    # Add your CPU information retrieval logic here
    cpu_info=$(lscpu)
    echo "$cpu_info"
}

# Function to display kernel information
display_kernel_info() {
    echo "Kernel Information:"
    # Add your kernel information retrieval logic here
    kernel_info=$(uname -a)
    echo "$kernel_info"
}

# Function to display free memory
display_free_memory() {
    echo "Free Memory:"
    # Add your free memory retrieval logic here
    free_mem=$(free -m)
    echo "$free_mem"
}

# Function to display system information
display_system_info() {
    echo "System Information:"
    # Add your system information retrieval logic here
    sys_info=$(uname -snrmo)
    echo "$sys_info"
}

# Main script logic
case $1 in
    -h|--help)
        display_help
        ;;
    -c|--cpu)
        display_cpu_info
        ;;
    -k|--kernel)
        display_kernel_info
        ;;
    -m|--free-memory)
        display_free_memory
        ;;
    -s|--system-info)
        display_system_info
        ;;
    *)
        echo "Invalid option. Use '-h' or '--help' to see available options."
        ;;
esac
