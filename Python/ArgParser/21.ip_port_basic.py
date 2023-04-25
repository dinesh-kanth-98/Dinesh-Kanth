import argparse

# Create the parser object
parser = argparse.ArgumentParser(description='Example script for argparse',epilog="example of args parsers")

# Add some positional arguments must to run the program 
parser.add_argument('ip', type=str, metavar='ipOfDevice', help='ipaddress of device')
parser.add_argument('port', type=int, help='port no to connect')
# parser.add_argument('--name', default='World', help='name to greet')

# Parse the arguments
args = parser.parse_args()

# Access the values of the arguments
ip = args.ip
port = args.port

print(f"ip:{ip}")
print(f"port:{port}")
