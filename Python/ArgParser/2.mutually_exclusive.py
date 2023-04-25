"""In Python's argparse module, a mutually exclusive group is a way to ensure that only
one option or argument within a group is used at a time. This is useful when you have multiple
options that are mutually exclusive and you want to prevent the user from specifying more 
than one.

# To create a mutually exclusive group, you can use the add_mutually_exclusive_group method
of the ArgumentParser object. This method returns a new ArgumentGroup object, which you can 
use to add options or arguments that are mutually exclusive"""

import argparse

parser = argparse.ArgumentParser()
group = parser.add_mutually_exclusive_group()
group.add_argument('--verbose','-v', action='store_true', help='enable verbose output')
group.add_argument('--quiet', action='store_true', help='suppress output')

# In Python's argparse module, the store_true action is used to define a boolean flag option 
# that sets the value of a corresponding attribute to True if the option is specified on the 
# command line, and to False otherwise.

args = parser.parse_args()

if args.verbose:
    print('Verbose output enabled')
elif args.quiet:
    print('Output suppressed')
else:
    print('Standard output')
