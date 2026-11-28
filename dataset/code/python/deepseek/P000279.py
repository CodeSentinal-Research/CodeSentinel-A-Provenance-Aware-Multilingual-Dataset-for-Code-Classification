def group_anagrams(strings):
    groups = {}
    for string in strings:
        sorted_string = ''.join(sorted(string))
        if sorted_string in groups:
            groups[sorted_string].append(string)
        else:
            groups[sorted_string] = [string]
    return list(groups.values())

def main():
    N = int(input().strip())
    strings = [input().strip() for _ in range(N)]
    anagrams = group_anagrams(strings)
    for group in anagrams:
        print(' '.join(group))

if __name__ == '__main__':
    main()