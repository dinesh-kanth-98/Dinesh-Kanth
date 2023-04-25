#!/bin/bash
#developed by Dinesh Kanth
#V01R01
. "/home/dinesh/dinesh/FINAL_FILES/Colors_Include[V01R01].sh"
OPTION=""
FILE_NAME="/home/dinesh/.bash_aliases"

ReadAndValidate(){
	echo -en "${BIBlack}"
	read -p "please choose any no from 1 to 8:" OPTION
	echo -en "${Color_Off}"
	if [ $OPTION -lt 1 ] || [ $OPTION -gt 8 ];
	then
		BRED "ERROR:$OPTION is a Wrong Option"
		ReadAndValidate
	fi
}

StartFromHere() {
	YESNO=""
	OVERWRIGHT=0
	BASENAME=$(basename "$(pwd)")

	if [ "${BASENAME^^}" != "BUILD" ] ;
	then 
		BRED "ERROR:current path is not build exiting"
		exit 1
	else
		BIYELLOW "${On_Blue}********   build path found   ********"
	fi

	ALIAS_SHORTCUTS=(' ' 'AB' 'AFB' 'VB' 'PB' 'ABE' 'AFBE' 'VBE' 'PBE')

	ICYAN "Which alias Shortcut Do You Want To Replace:"
	for ((i=1 ; i < ${#ALIAS_SHORTCUTS[@]} ; i++))
	do 
		IPURPLE "\t$i) --> alias ${ALIAS_SHORTCUTS[$i]}"
	done
	ReadAndValidate

	LINE_NO=$(awk "/alias ${ALIAS_SHORTCUTS[$OPTION]}/ { print NR }" ${FILE_NAME})
	if [ "${LINE_NO}" != "" ];
	then
		BIGREEN "alias ${ALIAS_SHORTCUTS[$OPTION]} Found In ${FILE_NAME}, Line No:$LINE_NO" 
		sed -n "${LINE_NO}p" $FILE_NAME
		echo -en "${BIYellow}"
		read -rp "Do You Want To Replace it with `pwd` (y/n):" YESNO
		echo -en "${Color_Off}"
		OVERWRIGHT=1
	else
		IRED "alias ${ALIAS_SHORTCUTS[$OPTION]} Not Found In ${FILE_NAME}" 
		echo -en "${BIYellow}"
		read -p "Do You Want To Write it with `pwd` (y/n):" YESNO
		echo -en "${Color_Off}"
	fi
	[ ${YESNO} == "y" ] || { BRED "WARNING:yes not choosen exiting";exit; }
	TEMP_ALIAS="alias ${ALIAS_SHORTCUTS[$OPTION]}=\"cd `pwd`\""
	if [ $OVERWRIGHT == 1 ]
	then
		sed -i "${LINE_NO}s|.*|${TEMP_ALIAS}|" $FILE_NAME
	else
		echo "${TEMP_ALIAS}" >> ${FILE_NAME}
	fi
	echo -e "${On_Purple}${BCyan} $TEMP_ALIAS ${Color_Off}"
}

StartFromHere
