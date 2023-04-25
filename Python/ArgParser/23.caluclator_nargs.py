import argparse

class MyHelpFormatter(argparse.HelpFormatter):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._max_help_position = 50

# Create the argument parser
parser = argparse.ArgumentParser(description='A simple calculator program'
                                ,formatter_class=MyHelpFormatter)

# Add the arguments
parser.add_argument('--operator', type=str
                                ,choices=['+', '-', '*', '/']
                                , help='the operator (%(choices)s)'
                                ,required=True)

parser.add_argument('--numbers', type=float
                                , nargs=2
                                , help='give two numbers'
                                , required=True
                                , metavar=('num1', 'num2'))

# Parse the arguments
args = parser.parse_args()

# Perform the calculation based on the operator
print(args.numbers[0])

match args.operator:
    case '+':
        result = args.numbers[0] + args.numbers[1]
    case '-':
        result = args.numbers[0] - args.numbers[1]
    case '*':
        result = args.numbers[0] * args.numbers[1]
    case '/':
        result = args.numbers[0] / args.numbers[1]

# Print the result
print(f'{args.numbers[0]} {args.operator} {args.numbers[1]} = {result}')
