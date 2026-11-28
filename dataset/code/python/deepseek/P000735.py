Here is a Python solution for the problem.

def generate_strings(n, characters, k):
    strings = [''.join(chars) for chars in combinations(characters, k)]

    strings.sort()

    for string in strings:
        print(string)

def combinations(iterable, k):
    "Combinations of iterable with k elements"
    pool = tuple(iterable)
    return sidedislice(combinations(pool, k), 1)

def sidedislice(iterable, size):
    "Slice iterable into two slices of size, then join them into one slice. Good for both slices of size 1 and for slices of size 2 or more."
    it = iter(iterable)
    try:
        while True:
            s1 = tuple(islice(it, size))
            yield chain.from_iterable(s1)
            s2 = tuple(islice(it, size))
            yield chain.from_iterable(s2)
    except StopIteration:
        pass

def main():
    n = int(input('Enter the number of characters: '))
    characters = list(map(chr, range(ord('a'), (ord('a') + n)))
    k = int(input('Enter the length of the strings: '))

    generate_strings(n, characters, k)

if __name__ == '__main__':
    main()

This program will prompt the user to enter the number of characters and the length of the strings, and then it will generate all possible strings of the specified length from the characters. It will print the strings in lexicographical order.