#!/bin/bash

# Define text formatting for color output
ICyan='\033[0;96m'     # Cyan
BIWhite='\033[1;97m'   # White
BIRed='\033[1;91m'     # Red
BIYellow='\033[1;93m'  # Yellow
IYellow='\033[0;93m'   # Yellow
BIGreen='\033[1;92m'   # Green
C_Off='\033[0m'        # Text Reset

# Define project and directory names
MAIN_DIRECTORY="SSH_Login"
SUB_DIRECTORY="Exp_Files"
ALIAS_FILE=".bash_aliases"
PRESENT_PATH="$(pwd)"

# Function to create a directory
Create_Directory() {
    local folderName
    folderName="$2""/""$1"
    
    # Check if the directory doesn't exist and create it
    [ ! -d "${folderName}" ] && {
        mkdir "${folderName}" && ( echo -e "${BIGreen}$1 folder created in $2 path${C_Off}"
        ) || ( echo -e "${BIRed}failed to create $1 folder in $2 path${C_Off}"; exit_fun; )
    } || {
        echo -e "${ICyan}$1 folder already present in $2 path${C_Off}";
    }
}

# Function to copy required files
Copy_Required_Files() {
    local folderName
    cd ${PRESENT_PATH}
    folderName=$HOME"/""${MAIN_DIRECTORY}/"
    echo -e "${BIYellow}\n**************** Copying Required Files **************** ${C_Off}"
    
    # Copy the required files to the specified directory
    Copy_File Passwd-64bit ${folderName}
    Copy_File Generate_Password.sh ${folderName}
    Copy_File ssh_login.exp ${folderName}
    Copy_File Passwd ${folderName}
}

# Function to copy a file
Copy_File() {
    cp -f $1 $2 && ( echo -e "${BIGreen}copied $1 file to $2 folder ${C_Off}"
    ) || ( echo -e "${BIRed}$1 file copy failed${C_Off}"; exit_fun; )
}

# Function to create a file
Create_File() {
    local fileName
    fileName="$2""/""$1"
    
    # Check if the file doesn't exist and create it
    [ ! -f "${fileName}" ] && {
        touch "${fileName}" && ( echo -e "${BIGreen}$1 file created in $2 path${C_Off}"
        ) || ( echo -e "${BIRed}failed to create $1 file in $2 path${C_Off}"; exit_fun; )
    } || {
        echo -e "${ICyan}$1 file already present in $2 path${C_Off}";
    }
}

# Function to set alias shortcuts
Set_Alias_Shortcuts() {
    local folderName
    folderName=$HOME"/""${MAIN_DIRECTORY}"
    
    # Define and set alias shortcuts
    echo -e "${BIYellow}\n*************** Writing Alias Shortcuts ************** ${C_Off}"
    alias="alias gp='cd ${folderName}; ./Generate_Password.sh && cd ${SUB_DIRECTORY}'"
    Is_Alias_Present "alias gp=" "$alias"
    echo ""
    
    alias="alias sd=\"sed -n '6,10p' \$1\""
    Is_Alias_Present "alias sd=" "$alias"
    echo ""
    
    folderName=$HOME"/""${MAIN_DIRECTORY}""/${SUB_DIRECTORY}"
    alias="alias cdef='cd ${folderName}'"
    Is_Alias_Present "alias cdef=" "$alias"
    echo ""
}

# Function to check if an alias is already defined and add it if not
Is_Alias_Present() {
    local aliasStatus
    aliasStatus=`( grep "$1" ~/${ALIAS_FILE} > /dev/null 2>&1 ) && echo "There" || echo "Not There"`
    
    # If the alias is not defined, add it to the .bash_aliases file
    [ "${aliasStatus}" = "Not There" ] && {
        echo -e "${ICyan}$2";
        echo "${alias}" >> ~/${ALIAS_FILE} && ( echo -e "${BIGreen}shortcut written in .bash_aliases file${C_Off}";
        ) || ( echo -e "${BIRed}failed to write in .bash_aliases file${C_Off}"; )
    } || {
        echo "$2";
        echo -e "${BIRed}$1 shortcut already present in ${ALIAS_FILE} file${C_Off}";
    }
}

# Function to exit the script
exit_fun() {
    echo -e "${IYellow}\n***********************${BIRed} EXITING ${IYellow}***********************${C_Off}"
    exit 1
}

# Function to install the Expect binary
Install_Expect_binary() {
    echo -e "${BIYellow}************ Installing Expect Binary ************ ${C_Off}"
    
    # Install Expect binary from the specified .deb files
    sudo dpkg -i ExpectBinary/libtcl8.6_8.6.8+dfsg-3_amd64.deb
    sudo dpkg -i ExpectBinary/tcl-expect_5.45.4-1_amd64.deb
    sudo dpkg -i ExpectBinary/expect_5.45.4-1_amd64.deb
    
    # Check if Expect is installed
    which expect && echo -e "${BIGreen}Expect Installation Success${C_Off}" || {
        echo -e "${BIRed}Expect Installation Failed${C_Off}";
        exit_fun;
    }
}

# Main function
Main() {
    echo -e "${ICyan}******************** ${BIYellow}SETUP STARTED ${ICyan}******************** ${C_Off}"

    # Check if Expect binary is installed, and install if not
    ( which expect > /dev/null 2>&1 ) || Install_Expect_binary

    # Create required directories and copy files
    echo -e "${BIYellow}************ Creating Required Directories ************ ${C_Off}"
    Create_Directory "${MAIN_DIRECTORY}" $HOME
    cd $HOME
    cd "${MAIN_DIRECTORY}" && echo "" || exit_fun;
    Create_Directory ${SUB_DIRECTORY} "$(pwd)"
    Copy_Required_Files

    # Check for the existence of .bash_aliases file
    echo -e "${BIYellow}\n************* Checking ${ALIAS_FILE} File ************ ${C_Off}"
    Create_File "${ALIAS_FILE}" $HOME

    # Set alias shortcuts
    Set_Alias_Shortcuts
    chmod -R 777 ~/"${MAIN_DIRECTORY}"
    
    # Provide user instructions
    echo -e "${IYellow}Execute ${BIWhite}source ~/.bash_aliases ${IYellow}Command To Refresh Aliases${C_Off}"
    echo
    echo -e "${ICyan}***********************${BIGreen} SETUP DONE ${ICyan}************************${C_Off}"
}

# Execute the main function
Main
