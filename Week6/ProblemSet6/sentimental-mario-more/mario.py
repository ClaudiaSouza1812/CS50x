# definition of main function
def main():
    # call the function to return the height of the pyramid
    pyramid_height = get_height()
    # variables to keep track of the following loops
    n = 1
    c = 1
    w = pyramid_height

    # piramid builder, prompt the lines
    # space holder, prompt the columns
    # hashtag holder, prompt the columns
    for i in range(pyramid_height):
        for j in range(n):
            print(" " * (w - n), end="")
        for k in range(n):
            print("#" * c, end="")
        for l in range(n):
            print("  ", end="")
        for m in range(n):
            print("#" * c, end="")
            print()
        c += 1
        w -= 1

# definition of the get_height function


def get_height():
    # while number isn't positive, keep prompting user the value
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
        except ValueError:
            print("Not an integer")


# calling main to run the entire code


main()