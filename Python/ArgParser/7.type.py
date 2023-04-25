import argparse

""" example to add custom type """
# Define a function that checks the validity of the argument value


def positive_int(value):
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError(
            "%s is not a positive integer" % value)
    return ivalue


# Create the ArgumentParser object
parser = argparse.ArgumentParser()

# Add an argument with the positive_int function as the type parameter
parser.add_argument('--number', type=positive_int,
                    help='an integer greater than 0')

# Parse the command line arguments
args = parser.parse_args()

# Use the validated argument value
print(args.number)
