def find_anagrams(s, p):
    from collections import Counter
    p_counter = Counter(p)
    s_counter = Counter()
    result = []

    for i, c in enumerate(s):
        s_counter[c] += 1
        if s_counter == p_counter:
            result.append(i - len(p) + 1)
        if i >= len(p):
            s_counter[s[i - len(p)]] -= 1

    return result

def main():
    s = input().strip()
    p = input().strip()
    indices = find_anagrams(s, p)
    print(indices)

if __name__ == '__main__':
    main()