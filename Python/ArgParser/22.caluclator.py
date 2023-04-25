import argparse

# Create the argument parser
parser = argparse.ArgumentParser(description='A simple calculator program')

# Add the arguments
parser.add_argument('operator', type=str, choices=['+', '-', '*', '/'], help='the operator (+, -, *, /)')
parser.add_argument('num1', type=float, help='the first number')
parser.add_argument('num2', type=float, help='the second number')

# Parse the arguments
args = parser.parse_args()

# Perform the calculation based on the operator

match args.operator:
    case '+':
        result = args.num1 + args.num2
    case '-':
        result = args.num1 - args.num2
    case '*':
        result = args.num1 * args.num2
    case '/':
        result = args.num1 / args.num2

# Print the result
print(f'{args.num1} {args.operator} {args.num2} = {result}')
