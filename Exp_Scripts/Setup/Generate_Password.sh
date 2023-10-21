#!/bin/bash

# Array of device names
declare -ra DEVICES=("pc" "system" "device" "laptop" "mac" "windows")

# Define text formatting for color output
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White
BIRed='\033[1;91m'        # Red
BIPurple='\033[1;95m'     # Purple
BCyan='\033[1;36m'        # Cyan
BIYellow='\033[1;93m'     # Yellow
IGreen='\033[0;92m'       # Green
BIGreen='\033[1;92m'      # Green
C_Off='\033[0m'           # Text Reset

# Variables to store user input
declare -u MAC=""
IP=""
PASSWORD=""
APPL_DEST_FILE=""
APPL_FILE="ssh_login.exp"
PATH_TO_COPY="${HOME}/SSH_Login/Exp_Files/"
SMALL_PASS=""

# Function to get the type of device from the user
GetDeviceType() {
    declare -i noOfDevices=${#DEVICES[@]}

    echo -e "${BIYellow}**************  Click On Ctrl + c or Ctrl + z To Exit  ****************${C_Off}"
    echo 
    echo -e "${BICyan}Device list (Enter between 1 to ${noOfDevices}):${C_Off}"
    PS3=$'\033[0;92mChoose Device: \033[0m'
    echo -en "${BIWhite}"
    
    select CHOSEN_DEVICE in "${DEVICES[@]}"; do
        echo -en "${BIWhite}"
        DEVICE_INDEX="$REPLY"
        echo "${DEVICE_INDEX}" | grep -q '^[0-9]\+$'

        if [ $? -eq 1 ]; then
            echo -e "${BIRed}Wrong Input, Enter between 1 to ${noOfDevices}${C_Off}"
        else
            if [[ ${DEVICE_INDEX} -lt 1 || ${DEVICE_INDEX} -gt ${noOfDevices} ]]; then
                echo -e "${BIRed}Wrong Input, Enter between 1 to ${noOfDevices}${C_Off}"
            else
                echo -e "${BIPurple}Chosen Device:${BIYellow} ${CHOSEN_DEVICE}${C_Off}" && echo
                break
            fi
        fi
    done
}

# Function to get the IP address from the user
GetIpFromUser() {
    declare -ar networks=("191.168.122.0" "191.168.161.0" "191.168.10.0" "192.168.80.0")
    declare -i noOfNetworks=${#networks[@]}
    local chosenNetwork=""
    declare input=""

    echo -e "${BICyan}In Which Network ${CHOSEN_DEVICE} Device Present, (Enter between 1 to ${noOfNetworks}):${C_Off}"
    PS3=$'\033[0;92mChoose Network: \033[0m'
    echo -en "${BIWhite}"
    
    select chosenNetwork in "${networks[@]}"; do
        input="$REPLY"
        echo "${input}" | grep -q '^[0-9]\+$'
        
        if [ $? -eq 1 ]; then
            echo -e "${BIRed}Wrong Input, Enter between 1 to ${noOfNetworks}${C_Off}"
        else
            if [[ ${input} -lt 1 || ${input} -gt ${noOfNetworks} ]]; then
                echo -e "${BIRed}Wrong Input, Enter between 1 to ${noOfNetworks}${C_Off}"
            else
                echo -e "${BIPurple}Chosen Network: ${BIYellow}${chosenNetwork}${C_Off}" && echo
                break
            fi
        fi
    done

    IP=${chosenNetwork%0*}
    local lastThreeLetters
    declare -i invalidIp=0
    
    echo -en "${BICyan}Enter Last Octet of ${CHOSEN_DEVICE} Device IP Address: ${C_Off}"
    read lastThreeLetters
    
    while true; do
        [ ${invalidIp} -eq 1 ] && {
            echo -en "${IGreen}Enter Last Three Letters: ${C_Off}"
            read lastThreeLetters
        }
        
        echo "${lastThreeLetters}" | grep -q '^[0-9]\+$'
        
        if [ $? -eq 1 ]; then
            echo -e "${BIRed}Wrong Input, Enter between 1 to 254${C_Off}"
            invalidIp=1
        else
            if [[ ${lastThreeLetters} -lt 1 || ${lastThreeLetters} -gt 254 ]]; then
                echo -e "${BIRed}Wrong Input, Enter between 1 to 254${C_Off}"
                invalidIp=1
            else
                IP=${IP}${lastThreeLetters}
                echo -e "${BIPurple}IP Address of ${CHOSEN_DEVICE} Device:${BIYellow} ${IP}${C_Off}" && echo
                break
            fi
        fi
    done
}

# Function to get the MAC address from the user
GetTheMacAddressFromUser() {
    echo -e "${BICyan}Enter MAC Address of ${CHOSEN_DEVICE} Device, Caps or Small No Problem:${C_Off}"
    
    while true; do
        echo -en "${IGreen}Enter MAC: ${C_Off}"
        read  MAC
        
        if echo "$MAC" | grep -qE '^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$'; then
            echo -e "${BIPurple}MAC Address of ${CHOSEN_DEVICE} Device:${BIYellow} ${MAC}${C_Off}" && echo
            break
        else
            echo -e "${BIRed}Invalid MAC address${C_Off}"
        fi
    done

    PASSWORD=$(./Passwd ${MAC})
    SMALL_PASS=$(./Passwd-64bit ${MAC})
    SMALL_PASS=$(echo ${SMALL_PASS} | cut -d " " -f3)
}

# Function to prepare the destination file name from the IP address
PrepareDestinationFileFromIP() {
    local macWithOutColon=""
    IFS="."
    
    read -a myIp <<<"${IP}"
    macWithOutColon=${MAC//:/}
    APPL_DEST_FILE="${myIp[-1]}""${myIp[-2]}""${macWithOutColon}"".exp"
}

# Function to write data to the SSH login configuration file
WriteDataToFile() {
    ((--DEVICE_INDEX))
    sed -i "6s|.*|set  DeviceName  ${DEVICES[DEVICE_INDEX]}|" "${APPL_FILE}"
    sed -i "7s|.*|#set Mac         ${MAC} |" "${APPL_FILE}"
    sed -i "8s|.*|#set Pass-64bit  ${SMALL_PASS} |" "${APPL_FILE}"
    sed -i "9s|.*|set  IP          \"${IP}\"|" "${APPL_FILE}"
    sed -i "10s|.*|set Password    \"${PASSWORD}\"|" "${APPL_FILE}"
    sed -i "11s|.*|set User        \"se\"|" "${APPL_FILE}"
}

# Function to copy the file to the destination path
CopyFileToDestinationPath() {
    [ ! -d "Exp_Files" ] && mkdir Exp_Files
    cp -rf "${APPL_FILE}" "${PATH_TO_COPY}${APPL_DEST_FILE}" && echo -e "${BIYellow}${APPL_DEST_FILE} ${BIGreen}Copied To${BIYellow} ${PATH_TO_COPY} ${BIGreen}Path${C_Off}"
    chmod 777 "${PATH_TO_COPY}${APPL_DEST_FILE}"
}

# Main function to execute the SSH login setup
Main() {
    GetDeviceType
    GetIpFromUser
    GetTheMacAddressFromUser
    PrepareDestinationFileFromIP
    WriteDataToFile
    CopyFileToDestinationPath
}
Main
