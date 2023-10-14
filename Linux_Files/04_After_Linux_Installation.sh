#!/bin/bash

# Define text formatting escape codes for colors and styles
BGreen='\033[1;32m'  # Green
BYellow='\033[1;33m'  # Yellow
IRed='\033[0;91m'  # Red
IGreen='\033[0;92m'  # Green
IYellow='\033[0;93m'  # Yellow
IBlue='\033[0;94m'  # Blue
IPurple='\033[0;95m'  # Purple
ICyan='\033[0;96m'  # Cyan
BBlack='\033[1;30m'  # Black
BRed='\033[1;31m'  # Red
BGreen='\033[1;32m'  # Green
BYellow='\033[1;33m'  # Yellow
BBlue='\033[1;34m'  # Blue
BPurple='\033[1;35m'  # Purple
BCyan='\033[1;36m'  # Cyan
BWhite='\033[1;37m'  # White
Color_Off='\033[0m'  # Text Reset
BIWhite='\033[1;97m'  # White

# Define an array of applications to be installed
Appl=("vim" "gcc" "vlc" "preload" "gnome-tweaks" "gnome-shell-extensions" "gnome-shell-extension-manager"
	"konsole" "dolphin" "copyq" "make" "curl" "meld" "expect" "zlib1g-dev" "qtcreator")

# Function to display success, failure, or installation messages with colors
Success_Fail_Message() {
	local title message COLOR BGRD cols titleSize charLine textSpan charTextOfSpanSize
	title="$1"
	message="$2"

    # Check if the message is for a successful installation
    if [ "$message" = "success" ]; then
	    COLOR=${BGreen}
	    BGRD=${ICyan}
	    message=" Installation success"
	    title+=$message
	    # Check if the message is for a failure during installation
    elif [ "$message" = "fail" ]; then
	    COLOR=${BYellow}
	    BGRD=${IRed}
	    message=" Installation Failed"
	    title+=$message
	    # Check if the message is for an installation in progress
    elif [ "$message" = "install" ]; then
	    COLOR=${BWhite}
	    BGRD=${IBlue}
	    title="installing "$title
	    echo ""
	    echo ""
    fi

    cols=$(tput cols)
    titleSize=${#title}
    # Calculate the span to center-align the title
    charLine="$(printf "%${cols}s" " " | tr " " "#")"
    textSpan=$(((cols - titleSize - 6) / 2))
    charTextOfSpanSize="$(printf "%${textSpan}s" " " | tr " " "-")"

    # Apply text formatting and print the formatted title
    title="${COLOR}${title^^}${Color_Off}"
    echo -e "${BGRD}$charLine"
    printf "%b" "${BGRD}$charTextOfSpanSize"
    printf "%b" "   $title   "
    printf "%b\n" "${BGRD}$charTextOfSpanSize"
    echo -e "${BGRD}$charLine${Color_Off}"
}

# Function to print a message with specific formatting
Print_Message() {
	local title message COLOR BGRD cols titleSize charLine textSpan charTextOfSpanSize
	title="$1"

	BGRD=${IPurple}
	COLOR=${BYellow}

	cols=$(tput cols)
	titleSize=${#title}
	# Calculate the span to center-align the title
	textSpan=$(((cols - titleSize - 6) / 2))
	charTextOfSpanSize="$(printf "%${textSpan}s" " " | tr " " "-")"

    # Apply text formatting and print the formatted title
    title="${COLOR}${title^*}${Color_Off}"
    echo ""
    echo ""
    printf "%b" "${BGRD}$charTextOfSpanSize"
    printf "%b" "   $title   "
    printf "%b\n" "${BGRD}$charTextOfSpanSize"
    echo -en "${Color_Off}" # ${BGRD}$charLine
}

# Function to install an application and display the installation status
installApplication() {
	appl="$1"
	Success_Fail_Message "$appl" "install"

    # Attempt to install the application using 'apt' and display success or failure message
    sudo apt install $appl -y && { Success_Fail_Message "$appl" "success"; return 0; } || { Success_Fail_Message "$appl" "fail"; return 1; }
}


declare -g  exit_status
# Function to run a command and print its status
run_command() 
{
	echo ""
	echo ""
	command="$1"
	echo -e "${BIWhite}Executing: ${IYellow}$command${Color_Off}"

    # Run the command and capture its exit status
    $command
    exit_status=$?

    if [ $exit_status -eq 0 ]; then
	    echo -e "${IGreen}Command completed successfully with status code: $exit_status${Color_Off}"
    else
	    echo -e "${IRed}Command failed with status code: $exit_status${Color_Off}"
    fi
}

# Function to install Git and configure it
installGITandConfigure() {
	installApplication "git"
	if [ $? == 0 ]; then
		run_command "$(git --version)"
		Print_Message "Confuguring git"
		# Uncomment and configure Git settings as needed
		run_command "git config --global user.name \"dinesh-kanth-98\""
		[ $exit_status == 0 ] &&  run_command "git config --global user.email \"chdinesh9948@gmail.com\"" || return 1
		[ $exit_status == 0 ] &&  run_command "mkdir ${HOME}/GIT" || return 1
		[ $exit_status == 0 ] &&  run_command "cd ${HOME}/GIT/" || return 1

		[ $exit_status == 0 ] && Print_Message "Cloning From https://github.com/dinesh-kanth-98/Dinesh-Kanth.git" || return 1
		[ $exit_status == 0 ] &&   run_command "git clone https://github.com/dinesh-kanth-98/Dinesh-Kanth.git" || return 1
		Print_Message "Copying Alias To Home Directory"
		[ $exit_status == 0 ] && run_command "cp ${HOME}/GIT/Dinesh-Kanth/Linux_Files/bash_aliases ${HOME}/.bash_aliases" || return 1
		# [ $exit_status == 0 ] && run_command "cp ${HOME}/GIT/Dinesh-Kanth/Linux_Files/bash_profile ${HOME}/.bash_profile" || return 1
		[ $exit_status == 0 ] && run_command "cp ${HOME}/GIT/Dinesh-Kanth/Linux_Files/konsole-tab-color.css ${HOME}/.konsole-tab-color.css" || return 1
	fi
}

# Function to install Grub Customizer
installGrubCustomiser() {
	Print_Message "Adding repository for Grub Customizer"
	run_command "sudo add-apt-repository ppa:danielrichter2007/grub-customizer"
	run_command "apt-get update"
	installApplication "grub-customizer"
}

# Function to install Visual Studio Code (VsCode)
installVsCode() {
	dependencies=("software-properties-common" "apt-transport-https" "wget")

    # Loop through the array of applications and install them
    for app in ${dependencies[@]}; do
	    installApplication "$app"
    done

    Print_Message "Downloading VsCode"
    run_command "wget https://go.microsoft.com/fwlink/?LinkID=760868 -O vscode.deb"

    Print_Message "Installing VsCode"
    [ $exit_status == 0 ] && run_command "sudo dpkg -i vscode.deb" || return 1
    [ $exit_status == 0 ] && run_command "sudo apt --fix-broken install" || return 1
	[ $exit_status == 0 ] && run_command "code --version" || return 1

    Print_Message "Installing VsCode Extentions"
    run_command "code --install-extension yzhang.markdown-all-in-one"
    run_command "code --install-extension yzane.markdown-pdf"
    run_command "code --install-extension DavidAnson.vscode-markdownlint"
    # run_command "code --install-extension yzhang.markdown-all-in-one"
    # run_command "code --install-extension yzhang.markdown-all-in-one"
    # run_command "code --install-extension yzhang.markdown-all-in-one"



}

# Function to install Google Chrome
installChrome() {
	Print_Message "Installing Chrome"
	run_command "wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb"
	run_command "sudo dpkg -i google-chrome-stable_current_amd64.deb"
	run_command "sudo apt-get install -f"
	run_command "sudo apt autoremove"
}

# Main function
Main() {
	Loop through the array of applications and install them
	  for app in ${Appl[@]}; do
	     installApplication "$app"
	done

	installGITandConfigure
	installGrubCustomiser
	installVsCode
	installChrome
}

# Exicution Starts From Here
Main
