# Simulate a sports tournament
# import needed libraries
import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage, which means checking if the file name is
    # written after the program name
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    # open the file in read mode and define the reader
    with open(sys.argv[1], "r") as csv_file:
        file_reader = csv.DictReader(csv_file)

        # TODO: Read teams into memory from file
        # create a list (teams) of dictionaries (dict_team)
        teams = []
        dict_team = dict()
        # iterate over file_reader rows, transform rating value from string
        # to integer data type, populate dict_team with the row data and append
        # the dictionary to teams list
        for row in file_reader:
            row["rating"] = int(row["rating"])
            dict_team = row
            teams.append(dict_team)

    # TODO: Simulate N tournaments and keep track of win counts
    counts = {}

    # populate counts list with the name and teams accumulated wins
    for i in range(N):
        key = simulate_tournament(teams)
        if key in counts.keys():
            counts[key] += 1
        else:
            counts[key] = 1

    # Print each team's percent chances of winning, according to simulation from highest
    # to lowest amount of wins
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


# a helper function that will be used inside the functions that follows it
def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]

    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    random_number = random.random()
    boolean_result = random_number < probability

    return boolean_result


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams within length of team list, iterating
    # the loop from two in two each time. Call the simulate_game function with 2 teams as
    # parameters, if its return is true, append the first team to winners list, append
    # the second team if the return is false
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = []
    winners = teams

    # keep calling simulate_round until the winners list have a champion
    while len(winners) > 1:
        winners = simulate_round(winners)

    return winners[0]["team"]


if __name__ == "__main__":
    main()
