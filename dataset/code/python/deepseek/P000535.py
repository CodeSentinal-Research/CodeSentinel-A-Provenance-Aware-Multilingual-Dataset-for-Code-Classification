Here is the Python code to solve the problem:

def deckRevealedIncreasing(deck):
    n = len(deck)
    index = collections.deque(range(n))
    ans = [None] * n

    for card in sorted(deck)[::-1]:
        ans[index.pop()] = card
        if index:
            index.appendleft(index.pop())

    return ans


def main():
    n = int(input())
    deck = list(map(int, input().split()))
    print(deckRevealedIncreasing(deck))


if __name__ == "__main__":
    main()

This Python code uses a double-ended queue (deque) to keep track of the order of the cards. The main function first gets the number of cards (n), and then the deck of cards. The input is processed and the output is printed.