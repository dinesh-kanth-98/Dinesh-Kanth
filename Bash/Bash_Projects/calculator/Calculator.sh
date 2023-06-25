#!/bin/bash

##
# @file Calculator.sh
#
# @brief This Is An Project On Caluclator Using Bash Script
##

# Declaring Read Only Array To Store Messages, It Is To Display Message On Screen While Reading Input From User
declare -ra DISP_MSG=("0-Enter First Number: " "1-Enter Second Number: " "2-Enter The Numerator: "
"3-Enter The Denominator: " "4-Enter the base: " "5-Enter the exponent: "
"6-Enter Number: ")

# Declaring Read Only Array To Store Messages, To Display Error Msg On Screen
declare -ra DISP_ERROR_MSG=("0-Operation Not Supported" "1-Not a Number, Enter Num Or Float"
"2-Max Attempts Reached, Please Try Again Later" "3-Invalid input. Please enter a number."
"3-Exponent should not ba a float, Please enter a number.")

# Declaring global Variable to Store Any Number Is Float or Not
declare -g NUM_IS_FLOAT=0

##
# @brief Check If The Input Is A Float
##
is_float() {
	re='^[0-9]+([.][0-9]+)+$' # regex Pattern For float Number
	if [[ $1 =~ $re ]]; then
		[ ${NUM_IS_FLOAT} -eq 0 ] && NUM_IS_FLOAT=1
	fi
}

##
# @brief Performs Division And Remainder Operations
##
Perform_Rem_Div_Operation() {

	:' We Will Recieve Function Arguments in $1 and $2
	Assigning to Local Variables For Better Understanding'
	local num1=$1 num2=$2

	# Using Case And OPERATION(Global Variable) To Perform Specific Operation
	case ${OPERATION} in
		/)
			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${num1} / ${num2}))"
				echo    "Result: " $((num1 / num2))


				echo -e "\nUsing let Syntax: let result=${num1}/${num2};echo \${result}:"
				echo    "Result: " $(let result=num1/num2; echo ${result})

				echo -e "\nUsing expr Syntax: \$(expr ${num1} / ${num2}))"
				echo    "Result: " $(expr $num1 / $num2)
			fi
			echo -e "\nUsing bc Syntax: echo \"${num1} / ${num2}\"| bc"
			echo    "Result: " $(echo "${num1} / ${num2}" | bc)
			;;
		%)
			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${num1} % ${num2}))"
				echo    "Result: " $((num1 % num2))

				echo -e "\nUsing let Syntax: let result=${num1}%${num2};echo \${result}:"
				echo    "Result: " $(let result=num1%num2; echo ${result})

				echo -e "\nUsing expr Syntax: \$(expr ${num1} % ${num2}))"
				echo    "Result: " $(expr $num1 % $num2)
			fi
			echo -e "\nUsing bc Syntax: echo \"${num1} % ${num2}\"| bc"
			echo    "Result: " $(echo "${num1} % ${num2}" | bc)
			;;
	esac

}

##
# @brief Reads Input From User And Validates Input Is A Number Or Float
##
Read_The_Number_From_User() {

	: ' the local -n syntax is used to create a local variable 
	that acts as a reference (or nameref)to another variable '
	local -n numRef=$1
	local msgToShow="$2"

	declare -i AttemptCount=0 # declaring Inteeger variable to count wrong input attempts from user
	local tempNum             # temparory variable to hold user input

	local numRe='^[0-9]+$'               # regex Pattern For Number
	local floatRe='^[0-9]+([.][0-9]+)?$' # regex Pattern For float Number

	while :; do
		if ((AttemptCount == 3)); then
			echo
			echo "${DISP_ERROR_MSG[2]#*-}"
			exit 0
		fi

		echo
		read -rp "[+] ${msgToShow}" tempNum

	# Check if 'tempNum' matches 'numRe' or 'floatRe' using regex pattern matching.
	if [[ ${tempNum} =~ ${numRe} || ${tempNum} =~ ${floatRe} ]]; then

	    # Using If Short Hand Feature To Call The is_float Function
	    [ ${NUM_IS_FLOAT} -eq 0 ] && is_float ${tempNum}

			# Assigning Temperory Num To The Actual Reference No After Successfull Validation
			numRef=${tempNum}
			break
		else
			echo "${DISP_ERROR_MSG[1]#*-}"
			let ++AttemptCount
	fi
done
}

##
# @brief Reads Input From User And Validates Input Is A Number Or Not
##
Read_And_Validate_The_Number() {
	: ' The local -n Syntax Is Used To Create A Local Variable 
	That Acts As A Reference (Or NameRef)To Another Variable '
	local -n numRef=$1
	local msgToShow="$2"

	declare -i AttemptCount=0 # declaring Inteeger variable to count wrong input attempts from user
	local tempNum             # temparory variable to hold user input
	local numRe='^[0-9]+$'    # regex Pattern For Number
    local floatRe='^[0-9]+([.][0-9]+)+$' # regex Pattern For float Number

	while :; do
		if ((AttemptCount == 3)); then
			echo "${DISP_ERROR_MSG[2]#*-}"
			exit 0
		fi

		echo
		read -rp "[+] ${msgToShow}" tempNum

		if [[ ${tempNum} =~ ${numRe} ]]; then
			numRef=${tempNum}
			break
        elif [[ ${tempNum}  =~ ${floatRe} ]]; then
            echo "${DISP_ERROR_MSG[4]#*-}"
			let ++AttemptCount
		else
			echo "${DISP_ERROR_MSG[3]#*-}"
			let ++AttemptCount
		fi
	done

}

##
# @brief Performs +,-,x Operations Depend on OPERATION(global variable)
##
Perform+-xOperation() {
    : 'we will Recieve Function Arguments in $1 and $2
    Assigning to Local Variables For Better Understanding'
    local num1=$1 num2=$2 result

	# using case and OPERATION(global variable) to perform specific operation
	case ${OPERATION} in
		+)
			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${num1} + ${num2}))"
				echo    "Result: " $((num1 + num2))


				echo -e "\nUsing let Syntax: let result=${num1}+${num2};echo \${result}:"
				echo    "Result: " $(let result=num1+num2; echo ${result})

				echo -e "\nUsing expr Syntax: \$(expr ${num1} + ${num2}))"
				echo    "Result: " $(expr $num1 + $num2)
			fi
			echo -e "\nUsing bc Syntax: echo \"${num1} + ${num2}\"| bc"
			echo    "Result: " $(echo "${num1} + ${num2}" | bc)
			;;

		-)
			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${num1} - ${num2}))"
				echo    "Result: " $((num1 - num2))

				echo -e "\nUsing let Syntax: let result=${num1}-${num2};echo \${result}:"
				echo    "Result: " $(let result=num1-num2; echo ${result})

				echo -e "\nUsing expr Syntax: \$(expr ${num1} - ${num2}))"
				echo    "Result: " $(expr $num1 - $num2)
			fi
			echo -e "\nUsing bc Syntax: echo \"${num1} - ${num2}\"| bc"
			echo    "Result: " $(echo "${num1} - ${num2}" | bc)
			;;

		x | X)
			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${num1} * ${num2}))"
				echo    "Result: " $((num1 * num2))


				echo -e "\nUsing let Syntax: let result=${num1}*${num2};echo \${result}:"
				echo    "Result: " $(let result=num1*num2; echo ${result})

				echo -e "\nUsing expr Syntax: \$(expr ${num1} \\* ${num2}))"
				echo    "Result: " $(expr $num1 \* $num2)
			fi
			echo -e "\nUsing bc Syntax: echo \"${num1} * ${num2}\"| bc"
			echo    "Result: " $(echo "${num1} * ${num2}" | bc)
			;;
	esac
}

##
# @brief Display Caluclator Options to User
##
Display_Message() {
	echo "**** Simple Caluclator project ****"
	echo
	echo -e "[+] enter + for Addition"
	echo -e "    enter - for Substraction"
	echo -e "    enter x for Multiplication"
	echo -e "    enter % for Remainder"
	echo -e "    enter / for Division"
	echo -e "    type sqrt for suare root"
	echo -e "    type x^ for power operation"
	echo
}

##
# @brief Caluclator Starts From Here
##
Main() {
	local firstNumber SecondNumber

	Display_Message

	echo
	read -rp "[+] enter ther operation you wanted perform: " OPERATION

	# Using Case And OPERATION(Global Variable) To Perform Specific Operation
	case ${OPERATION} in
		+ | - | x | X)
			# "${DISP_MSG[0]#*-}" Added double quote around it to stop Splitting Of space seperated String
			# #*- is to remove 'index-' in message from global array message
			Read_The_Number_From_User firstNumber "${DISP_MSG[0]#*-}"
			Read_The_Number_From_User SecondNumber "${DISP_MSG[1]#*-}"

			Perform+-xOperation ${firstNumber} ${SecondNumber}
			;;
		/ | %)
			Read_The_Number_From_User firstNumber "${DISP_MSG[2]#*-}"
			Read_The_Number_From_User SecondNumber "${DISP_MSG[3]#*-}"
			Perform_Rem_Div_Operation ${firstNumber} ${SecondNumber}
			;;
		"sqrt")
			Read_The_Number_From_User firstNumber "${DISP_MSG[6]#*-}"
			echo -e "\nUsing bc Syntax: echo \"scale=2;sqrt(\${firstNumber}\" | bc"
			echo    "Result: "    $(echo "scale=2;sqrt(${firstNumber})" | bc)
			;;
		"x^")
			Read_The_Number_From_User firstNumber "${DISP_MSG[4]#*-}"
			Read_And_Validate_The_Number SecondNumber "${DISP_MSG[5]#*-}"

			if [ ${NUM_IS_FLOAT} -eq 0 ]; then
				echo -e "\nUsing \$(()) Syntax: \$((${firstNumber} ** ${SecondNumber}))"
				echo    "Result: " $((firstNumber ** SecondNumber))

				echo -e "\nUsing let Syntax: let result=${firstNumber}**${SecondNumber};echo \${result}:"
				echo    "Result: " $(let result=firstNumber**SecondNumber; echo ${result})

				#expr doesn't support power operation
                #echo -e "\nUsing expr Syntax: \$(expr ${firstNumber} ** ${SecondNumber}))"
                #echo    "Result: " $(expr $firstNumber ** $SecondNumber)
			fi
			echo -e "\nUsing bc Syntax: echo \"${firstNumber} ^ ${SecondNumber}\"| bc"
			echo    "Result: " $(echo "${firstNumber} ^ ${SecondNumber}" | bc)
			;;

	# Adding Default Case To Handle Wrong Input From User
	*)
	echo -e "\n${DISP_ERROR_MSG[0]#*-}"
	exit 0
	;;
esac
}

# Main Script Execution Starts Here
Main
