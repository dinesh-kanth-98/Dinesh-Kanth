import argparse
# %(prog)s gives file name
#%(prog)s gives 
parser = argparse.ArgumentParser(
    usage='%(prog)s [options] output_file',
    description='My script does something',
    epilog='This is additional information'
)

parser.add_argument('--output', help='output file name')
args = parser.parse_args()


import argparse

# Create the argument parser with a custom usage message
parser = argparse.ArgumentParser(
    usage='%(prog)s [options] <num1> <num2>',
    description='A simple program to multiply two numbers'
)

# Add the arguments
parser.add_argument('num1', type=int, help='the first number')
parser.add_argument('num2', type=int, help='the second number')

# Parse the arguments
args = parser.parse_args()

# Multiply the numbers
result = args.num1 * args.num2

# Print the result
print(f'The product of {args.num1} and {args.num2} is {result}')

