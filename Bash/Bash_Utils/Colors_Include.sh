#!/bin/bash

# Reset
Color_Off='\033[0m'       # Text Reset
CO='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

#red color patterns
RED()
{
	echo -e "$2${Red}$1 ${Color_Off}"
}
BRED()
{
	echo -e "$2${BRed}$1 ${Color_Off}"
}
URED()
{
	echo -e "$2${URed}$1 ${Color_Off}"
}
IRED()
{
	echo -e "$2${IRed}$1 ${Color_Off}"
}
BIRED()
{
	echo -e "$2${BIRed}$1 ${Color_Off}"
}

#green color patterns
GREEN()
{
	echo -e "$2${Green}$1 ${Color_Off}"
}

BGREEN()
{
	echo -e "$2${BGreen}$1 ${Color_Off}"
}
IGREEN()
{
	echo -e "$2${IGreen}$1 ${Color_Off}"
}
BIGREEN()
{
	echo -e "$2${BIGreen}$1 ${Color_Off}"
}
UGREEN()
{
	echo -e "$2${UGreen}$1 ${Color_Off}"
}

#yellow color patterns
YELLOW()
{
	echo -e "$2${Yellow}$1 ${Color_Off}"
}
BYELLOW()
{
	echo -e "$2${BYellow}$1 ${Color_Off}"
}
IYELLOW()
{
	echo -e "$2${IYellow}$1 ${Color_Off}"
}
BIYELLOW()
{
	echo -e "$2${BIYellow}$1 ${Color_Off}"
}
UYELLOW()
{
	echo -e "$2${UYellow}$1 ${Color_Off}"
}

BLUE()
{
	echo -e "$2${Blue}$1 ${Color_Off}"
}
BBLUE()
{
	echo -e "$2${BBlue}$1 ${Color_Off}"
}
IBLUE()
{
	echo -e "$2${IBlue}$1 ${Color_Off}"
}
BIBLUE()
{
	echo -e "$2${BIBlue}$1 ${Color_Off}"
}
UBLUE()
{
	echo -e "$2${UBlue}$1 ${Color_Off}"
}

PURPLE()
{
	echo -e "${Purple}$1 ${Color_Off}"
}
BPURPLE()
{
	echo -e "${BPurple}$1 ${Color_Off}"
}
IPURPLE()
{
	echo -e "${IPurple}$1 ${Color_Off}"
}
BIPURPLE()
{
	echo -e "${BIPurple}$1 ${Color_Off}"
}
UPURPLE()
{
	echo -e "$2${UPurple}$1 ${Color_Off}"
}

CYAN()
{
	echo -e "$2${Cyan}$1 ${Color_Off}"
}
BCYAN()
{
	echo -e "$2${BCyan}$1 ${Color_Off}"
}
ICYAN()
{
	echo -e "$2${ICyan}$1 ${Color_Off}"
}
BICYAN()
{
	echo -e "$2${BICyan}$1 ${Color_Off}"
}
UCYAN()
{
	echo -e "$2${UCyan}$1 ${Color_Off}"
}

WHITE()
{
	echo -e "$2${White}$1 ${Color_Off}"
}
BWHITE()
{
	echo -e "$2${BWhite}$1 ${Color_Off}"
}
IWHITE()
{
	echo -e "$2${IWhite}$1 ${Color_Off}"
}
BIWHITE()
{
	echo -e "$2${BIWhite}$1 ${Color_Off}"
}
UWHITE()
{
	echo -e "$2${UWhite}$1 ${Color_Off}"
}

BLACK()
{
	echo -e "$2${Black}$1 ${Color_Off}"
}
BBLACK()
{
	echo -e "$2${BBlack}$1 ${Color_Off}"
}
IBLACK()
{
	echo -e "$2${IBlack}$1 ${Color_Off}"
}
BIBLACK()
{
	echo -e "$2${BIBlack}$1 ${Color_Off}"
}
UBLACK()
{
	echo -e "$2${UBlack}$1 ${Color_Off}"
}
