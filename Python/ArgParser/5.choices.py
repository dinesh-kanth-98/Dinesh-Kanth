# import argparse

# parser = argparse.ArgumentParser()
# parser.add_argument('--color', choices=['red', 'green', 'blue'], help='Choose a color ({choices})')
# args = parser.parse_args()

# print(args.color)

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--color',metavar="" ,choices=['red', 'green', 'blue'], help='Choose a color (%(choices)s)')
args = parser.parse_args()

print(args.color)


