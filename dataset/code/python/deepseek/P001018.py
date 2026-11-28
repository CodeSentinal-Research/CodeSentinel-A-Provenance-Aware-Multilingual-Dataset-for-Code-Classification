from collections import Counter

def reorganize_string(s):
    counter = Counter(s)
    max_count = max(counter.values())

    if max_count > (len(s) - max_count + 1):
        return 'IMPOSSIBLE'

    ans = ''
    for char, freq in counter.most_common():
        if ans[-1] == char:
            return 'IMPOSSIBLE'
        ans += char * freq

    return ans

def main():
    s = input()
    print(reorganize_string(s))

if __name__ == '__main__':
    main()