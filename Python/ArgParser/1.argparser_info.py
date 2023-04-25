import argparse

#"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
# epilog :- to display additional description of the program after the description 
#           of the arguments.
parser = argparse.ArgumentParser(description='Example script for argparse',epilog="example of args parsers")
#""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
""" Python's argparse module supports several types of command-line arguments that can be specified using the type parameter. Here are some of the most commonly used types:"""

# int: A signed integer value.
# 
# float: A floating-point value.
# 
# str: A string value (this is the default type).
# 
# bool: A boolean value (True or False). This type is not used directly;
#       instead, it is often used with the action='store_true' or 
#       action='store_false' parameters.
# 
# file: A filename. This type opens the file for reading or writing (depending on the
#       mode parameter, which defaults to 'r') and returns a file object.
# 
# pathlib.Path: A pathlib.Path object representing a filesystem path.

# Add some positional arguments must to run the program 
parser.add_argument('input_file', type=str, help='Path to input file')
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#---------------------------------------------------------------------------------
# metavar:- metavar parameter to customize the way the argument is displayed 
#          in the usage message. 

parser.add_argument('input', metavar='INPUT_FILE', help='input file name')
# 
# metavar=argparse.SUPPRESS :-when adding the --numbers argument. 
#                 This will prevent the metavar from being displayed in the optional 
#                 arguments section of the help message,
#                 but it will still be displayed in the usage message.

parser.add_argument('--numbers', type=int, nargs=2, metavar=argparse.SUPPRESS, 
                    help='two numbers to multiply together')
#--------------------------------------------------------------------------------



#''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
# options (or Optional Arguments):
#                 #short notation #long notation
parser.add_argument('-ip',        '--ipaddr',    type=str, help='Path to output file')

#to remove clutter for optional arguments keep metavar blank
parser.add_argument('--input_file', metavar='', help='input file name')

#required:- to make any optional arguments mandatory keep required true
parser.add_argument('--temp', required=True, metavar='', help='temp file name')
# 
#''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



#================================================================================================
""" In Python's argparse module, the nargs parameter is used to specify how many arguments 
    should be consumed for a single option or positional argument. It can be set to a variety
    of values depending on how many arguments are expected."""

# Here are some examples of how to use the nargs parameter:
#
# nargs=1: The option or argument takes exactly one value.
#
# nargs='+': The option or argument takes one or more values. 
#            The values are collected into a list.
#
# nargs='*': The option or argument takes zero or more values. 
#            The values are collected into a list.
# 
# nargs='?': This value means that the argument is optional and can be omitted.
#            If the argument is present on the command line, it will consume a single value.
#            If it is not present, it will use the default value specified by the default
#            parameter (if any).
#
# nargs=2: The option or argument takes exactly two values. 
#          The values are collected into a tuple.
#
# nargs=argparse.REMAINDER: All the remaining command-line arguments are 
#                               collected into a list.
# 
parser.add_argument('--files', nargs='+', metavar='', help='input files')
parser.add_argument('op', nargs=1, metavar='', help='output file')
#================================================================================================



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# In Python's argparse module, the store_false action is used to define a boolean flag option that sets the value of a corresponding attribute to False if the option is specified on the command line, and to True otherwise.
# In Python's argparse module, the store_true action is used to define a boolean flag option that sets the value of a corresponding attribute to True if the option is specified on the command line, and to False otherwise.
parser.add_argument('--no', action='store_false', help='disable output')
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# In Python's argparse module, you can use the default parameter to set a default value for an argument
parser.add_argument('--name', default='World', help='name to greet')
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#************************************************************************************************
# we can increase the space between options and help in help page
class MyHelpFormatter(argparse.HelpFormatter):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._max_help_position = 50

# Create the argument parser
parser = argparse.ArgumentParser(description='A simple calculator program'
                                ,formatter_class=MyHelpFormatter)
#************************************************************************************************


# Parse the arguments
args = parser.parse_args()

# Access the values of the arguments
input_file = args.input_file
output_file = args.output_file

# Use the arguments
print(f'Input file: {input_file}')
print(f'Output file: {output_file}')