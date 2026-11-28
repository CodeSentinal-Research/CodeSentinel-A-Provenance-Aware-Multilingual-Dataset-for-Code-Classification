Here's the Python code for the problem:

def longest_repeating_character_replacement(s, k):
    start, end = 0, 0
    freq = {}
    max_length = 0

    while end < len(s):
        if s[end] not in freq:
            freq[s[end]] = 1
        else:
            freq[s[end]] += 1

        max_length = max(max_length, freq[s[end]])

        if freq[s[end]] > k:
            freq[s[start]] -= 1
            start += 1

        end += 1

    return max_length

def main():
    s = input("Enter a string: ")
    k = int(input("Enter a number: "))
    print("Length of the longest substring is: ", longest_repeating_character_replacement(s, k))

if __name__ == "__main__":
    main()

This program uses a sliding window approach with two pointers to find the longest substring that can be made by replacing at most K characters. The frequency of each character is kept in a hash map. The maximum length is updated whenever a character's frequency is more than K. If a character's frequency is more than K, the sliding window moves the start pointer one step forward, thus reducing the frequency of that character. Finally, the maximum length is returned.