Here's the Python code:

def rankTeams(V, votes):
    teams = [[] for _ in range(26)]

    for vote in votes:
        for i, vote in enumerate(vote):
            teams[ord(vote) - 65].append(-i)

    ranking = ''.join(chr(i + 65) * (len(teams[i]) + 1) for i in range(26))

    return ranking.rstrip()


def main():
    V = int(input().strip())
    votes = [input().strip() for _ in range(V)]
    print(rankTeams(V, votes))


if __name__ == "__main__":
    main()

In this code, the `rankTeams` function first initializes an array of empty lists for each team. It then iterates over the votes, and for each vote, it adds the vote's index multiplied by -1 (since the index represents the vote's position in the ranking) to the corresponding list of teams. Finally, it joins the lists of teams together into a string, and returns this string.

The `main` function reads the number of votes and the votes themselves from the input, calls the `rankTeams` function with these values, and prints the result.