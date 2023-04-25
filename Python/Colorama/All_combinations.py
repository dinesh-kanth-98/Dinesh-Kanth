import colorama
from colorama import Fore, Back, Style

# Initialize colorama
colorama.init()

# Define a list of all available colors
colors = [Fore.BLACK, Fore.RED, Fore.GREEN, Fore.YELLOW, Fore.BLUE, Fore.MAGENTA, Fore.CYAN, Fore.WHITE]
colors_names = ["Fore.BLACK", "Fore.RED", "Fore.GREEN", "Fore.YELLOW", "Fore.BLUE", "Fore.MAGENTA", "Fore.CYAN", "Fore.WHITE"]

bg_colors = [Back.BLACK, Back.RED, Back.GREEN, Back.YELLOW, Back.BLUE, Back.MAGENTA, Back.CYAN, Back.WHITE]
bg_colors_names = ["Back.BLACK", "Back.RED", "Back.GREEN", "Back.YELLOW", "Back.BLUE", "Back.MAGENTA", "Back.CYAN", "Back.WHITE"]

# Loop through all combinations of colors and background colors
b_idx=0
for bg_color in bg_colors:
    c_idx=0
    for color in colors:
        print(color + bg_color + colors_names[c_idx] + "  " + bg_colors_names[b_idx] + Style.RESET_ALL)
        c_idx = c_idx + 1
    b_idx = b_idx + 1
        # print(color + bg_color + 'Hello, World!' + Style.RESET_ALL)
