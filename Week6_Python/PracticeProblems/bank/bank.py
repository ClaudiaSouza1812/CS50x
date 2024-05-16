import sys

greet = input("Enter your greet: ").strip().lower()

words = greet.split()

for word in words[0:]:
    if word[0:5] == "hello":
        print("$0")
        sys.exit(0)
    elif word != "hello" and word[0] == "h":
        print("$20")
        sys.exit(0)
    else:
        print("$100")
        sys.exit(0)
