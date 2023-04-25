import argparse

# Create the ArgumentParser object
parser = argparse.ArgumentParser()

# Add a positional argument with a default value
parser.add_argument('filename', nargs='?', default='default.txt'
                                , help='the name of the file to process')

# Parse the command line arguments
args = parser.parse_args()

# Use the parsed argument values
print(args.filename)
