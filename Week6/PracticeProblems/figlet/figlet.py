#import the needed libraries
import sys
import random
from pyfiglet import Figlet

#define a new object of Figlet class
figlet = Figlet()

#checks the correct number of arguments in the command line and deliver a different result
#depending on it
if len(sys.argv) == 1:
    #prompts the user a word or phrase and prints it in a random kind of font
    input = input("Input: ")
    font = random.choice(figlet.getFonts())
    figlet = Figlet(font=font)
    print(figlet.renderText(input))

elif len(sys.argv) == 3:
    #checks if was provided the right words in the command line
    if sys.argv[1] == "-f" or sys.argv[1] == "--font":
        font = sys.argv[2]
        #checks if the font inputed do exist
        if font in figlet.getFonts():
            #prompts the user a word or phrase and prints it in inputed kind of font
            input = input("Input: ")
            figlet = Figlet(font=sys.argv[2])
            print(figlet.renderText(input))
            sys.exit(0)
        else:
            print("Invalid usage")
            sys.exit(1)
    else:
        print("Invalid usage")
        sys.exit(1)
else:
    print("Invalid usage")
    sys.exit(1)
