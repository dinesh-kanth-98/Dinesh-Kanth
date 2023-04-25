import colorama
from colorama import Fore as FG,Style as SL
colorama.init(autoreset=True)

# col=["BLACK", "FG.RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE", "RESET"]

# print(print(f"{FG.colors[3]}Yellow Text"))
cols='''import colorama
from colorama import Fore as FG, Back as BG, Style as SL
colorama.init(autoreset=True)
'''
print(cols)

col="""print(f"{FG.WHITE} {SL.BRIGHT}Bright_WHITE_Text")"""
print(f"{FG.WHITE} {SL.BRIGHT}{col}")

col="""print(f"{FG.GREEN} {SL.BRIGHT}Bright_GREEN_Text")"""
print(f"{FG.GREEN} {SL.BRIGHT}{col}")

col="""print(f"{FG.RED} {SL.BRIGHT}Bright_RED_Text")"""
print(f"{FG.RED} {SL.BRIGHT}{col}")

col="""print(f"{FG.YELLOW} {SL.BRIGHT}Bright_YELLOW_Text")"""
print(f"{FG.YELLOW} {SL.BRIGHT}{col}")

col="""print(f"{FG.BLUE} {SL.BRIGHT}Bright_BLUE_Text")"""
print(f"{FG.BLUE} {SL.BRIGHT}{col}")

col="""print(f"{FG.MAGENTA} {SL.BRIGHT}Bright_MAGENTA_Text")"""
print(f"{FG.MAGENTA} {SL.BRIGHT}{col}")

col="""print(f"{FG.CYAN} {SL.BRIGHT}Bright_CYAN_Text")"""
print(f"{FG.CYAN} {SL.BRIGHT}{col}")

cols='''["BLACK", "FG.RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE", "RESET"]'''
print(cols)
