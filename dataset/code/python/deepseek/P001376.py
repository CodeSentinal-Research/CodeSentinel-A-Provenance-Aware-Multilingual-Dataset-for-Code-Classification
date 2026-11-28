Here is the Python code for the problem:

def main():
    n = int(input())
    strings = [input() for _ in range(n)]
    groups = {}

    for s in strings:
        sorted_s = ''.join(sorted(s))
        if sorted_s not in groups:
            groups[sorted_s] = [s]
        else:
            groups[sorted_s].append(s)

    for group in groups.values():
        print('\n'.join(sorted(group)))


if __name__ == "__main__":
    main()

This program works by first getting the number of strings from the input. Then it gets each string individually and sorts it. It uses a dictionary to group the sorted strings together. If a sorted string is not in the dictionary, it adds a new entry with the sorted string as the key and the original string as the value. If the sorted string is already in the dictionary, it appends the original string to the list of values for that key. Finally, it prints out the sorted strings for each group in lexicographical order.