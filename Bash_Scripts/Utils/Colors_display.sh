#!/bin/bash

# Reset
Color_Off='\033[0m'       # Text Reset

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

colors()
{
	colors=('Black' 'Red' 'Green' 'Yellow' 'Blue' 'Purple' 'Cyan' 'White')
	color_type=('Regular Color' 'Bold' 'Underline' 'High Intensity' 'Bold High Intensity')
	add_before=('' 'B' 'U' 'I' 'BI')

	for ((i=0 ; i<${#add_before[@]} ; i++))
	do
		for ((j=0 ; j<${#colors[@]} ; j++))
		do
			value=$(eval echo \${"${add_before[i]}""${colors[$j]}"})
			fun_name=${add_before[$i]}${colors[$j]}
			echo -e "$value color is ${color_type[$i]} ${colors[$j]} VarName: \${${add_before[$i]}${colors[$j]}} function: ${fun_name^^} ${Color_Off} "
		done
		echo
	done
}

BackGroundColors()
{
	BGRND=('Background' 'High Intensity background')
	BGRND_ADD_BEF=('On_' 'On_I')
	colors=('Black' 'Red' 'Green' 'Yellow' 'Blue' 'Purple' 'Cyan' 'White')
	color_type=('Regular Color' 'Bold' 'Underline' 'High Intensity' 'Bold High Intensity')
	add_before=('' 'B' 'U' 'I' 'BI')

	for ((i=0 ; i<${#BGRND_ADD_BEF[@]} ; i++))
	do
		for ((j=1 ; j<${#colors[@]} ; j++))
		do
			text_for_echo=${BGRND[$i]}
			BKGRD=$(eval echo \${"${BGRND_ADD_BEF[i]}""${colors[$j]}"})
			for ((k=0 ; k<${#add_before[@]} ; k++))
			do
				for ((l=0 ; l<${#colors[@]} ; l++))
				do
					fun_name=${add_before[$k]}${colors[$l]}
					value=$(eval echo \${"${add_before[k]}""${colors[$l]}"})
					echo -e "$BKGRD${value}on ${colors[$j]} ${text_for_echo}, Foreground color is ${color_type[$k]} ${colors[$l]}  function: ${fun_name^^} \"\" \${${BGRND_ADD_BEF[i]}""${colors[$j]}} \${${add_before[$k]}${colors[$l]}} ${Color_Off} "
				done
				echo
			done
		done
	done
}
tput_colors()
{
	declare -i i
	for i in $(seq 1 255); do
		tput setaf $i
		echo "echo \"\$(tput setaf $i) this_color_No_is_$i \$(tput sgr 0)\""
	done
}
[ "$1" == "tput" ] && { tput_colors;exit 0; }
[ -z "$1"] && colors || BackGroundColors
