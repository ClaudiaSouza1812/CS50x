
def main():
    score = get_scores()
    average = sum(score) / len(score)
    print(f"Average: {average:.2f}")


def get_scores():

    scores = []

    n = - 1
    while n <= 0 or n > 10:
        try:
            n = int(input("Enter how many scores there should be: "))
        except ValueError:
            print("Not an integer")

    c = 0
    while c != n:
        try:
            score = int(input("Score: "))
            scores.append(score)
            c += 1
        except ValueError:
            print("Not an integer")
    return scores


main()