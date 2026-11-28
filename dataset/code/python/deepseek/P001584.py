def longest_substring_with_k_vowels(s: str, k: int) -> int:
    vowels = set("aeiou")
    left = 0
    count = {vowels: 0 for vowel in vowels}
    max_length = 0

    for right, char in enumerate(s):
        count[char] += 1
        while count[char] > k:
            count[s[left]] -= 1
            left += 1
        max_length = max(max_length, right - left + 1)

    return max_length

def main():
    s = input().strip()
    k = int(input().strip())
    print(longest_substring_with_k_vowels(s, k))

if __name__ == "__main__":
    main()