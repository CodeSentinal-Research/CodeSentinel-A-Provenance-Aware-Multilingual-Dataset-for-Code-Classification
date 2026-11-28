def longest_substring(s, k):
    if k <= 0 or k > len(s):
        return 0
    left, right = 0, 0
    counter = dict()
    max_len = 0
    while right < len(s):
        counter[s[right]] = counter.get(s[right], 0) + 1
        while len(counter) >= k:
            counter[s[left]] -= 1
            if counter[s[left]] == 0:
                del counter[s[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
        right += 1
    return max_len

def main():
    s = input()
    k = int(input())
    print(longest_substring(s, k))

if __name__ == "__main__":
    main()