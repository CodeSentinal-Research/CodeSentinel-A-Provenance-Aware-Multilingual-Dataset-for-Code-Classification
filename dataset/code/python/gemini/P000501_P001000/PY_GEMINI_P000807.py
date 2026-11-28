from collections import defaultdict

def count_equal_vowels_consonants(s: str) -> int:
    vowels = set('aeiouAEIOU')
    prefix = 0
    count = 0
    freq = defaultdict(int)
    freq[0] = 1
    for ch in s:
        if ch.isalpha():
            prefix += 1 if ch in vowels else -1
            count += freq[prefix]
            freq[prefix] += 1
    return count

if __name__ == '__main__':
    s = input().strip()
    print(count_equal_vowels_consonants(s))