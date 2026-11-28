Here is the Python code:

def countSubarrays(s):
    vowels = set("aeiou")
    count = 0
    vowel_count = 0
    consonant_count = 0
    for c in s:
        if c in vowels:
            vowel_count += 1
            consonant_count = 0
        else:
            consonant_count += 1
            vowel_count = 0
        if vowel_count == consonant_count:
            count += 1
    return count

if __name__ == "__main__":
    s = input().strip()
    print(countSubarrays(s))

In this code, we maintain two counters: `vowel_count` and `consonant_count`. We increment `vowel_count` every time we encounter a vowel and `consonant_count` every time we encounter a consonant. If the vowel count equals the consonant count, we increment `count`.

The main function reads a string from stdin, calls `countSubarrays` with this string as input, and prints the result.

Note: This solution assumes that the input string only contains lowercase English letters and that the length of the string does not exceed the given constraints.