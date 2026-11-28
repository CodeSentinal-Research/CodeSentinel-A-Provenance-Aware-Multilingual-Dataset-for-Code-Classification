def longest_substring_with_k_distinct_characters(s, k):
    distinct_chars = [0] * 128
    start = max_length = 0
    for end, char in enumerate(s):
        distinct_chars[ord(char)] = end
        if len(distinct_chars) > k:
            max_distinct_char_start = min(distinct_chars[i] for i in range(128) if distinct_chars[i] >= start)
            start = max_distinct_char_start
            for i in range(start, end):
                distinct_chars[ord(s[i])] = end
    max_length = max(max_length, end - start + 1)
    return max_length

def main():
    s = input()
    k = int(input())
    print(longest_substring_with_k_distinct_characters(s, k))

if __name__ == "__main__":
    main()