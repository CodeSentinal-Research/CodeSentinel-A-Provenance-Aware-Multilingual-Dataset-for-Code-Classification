Here is the Python code:

def solve(N, K):
    happy_strings = ['a', 'b', 'c']

    while len(happy_strings) < N:
        new_happy_strings = ['a' + x + 'b' + y + 'c' + z for x in happy_strings for y in happy_strings for z in happy_strings]
        new_happy_strings = list(set(new_happy_strings))  
        happy_strings.extend(new_happy_strings)

    if K <= len(happy_strings):
        return sorted(happy_strings)[K - 1]
    else:
        return ''

def main():
    N, K = map(int, input().split())
    print(solve(N, K))

if __name__ == "__main__":
    main()

In this code, we start with ['a', 'b', 'c'] as the list of all possible happy strings. We then generate all possible happy strings by iterating over all possible combinations of 'a', 'b', and 'c' and adding them to the list of strings. We then sort the list of strings and return the K-th string. If there are less than K strings, we return an empty string.