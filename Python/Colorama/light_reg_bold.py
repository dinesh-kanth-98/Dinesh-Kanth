import colorama
from colorama import Fore, Back, Style

# Initialize colorama
colorama.init()

# Define a list of all available colors
colors = [Fore.BLACK, Fore.RED, Fore.GREEN, Fore.YELLOW, Fore.BLUE, Fore.MAGENTA, Fore.CYAN, Fore.WHITE]

# Loop through all colors and print both bold and light versions
for color in colors:
    print(color + 'This is regular ' + Style.BRIGHT + 'and this is bold ' + Style.RESET_ALL)
    print(color + 'This is light ' + Style.DIM + 'and this is regular ' + Style.RESET_ALL)
