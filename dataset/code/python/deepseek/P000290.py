Here is the Python code for finding all anagrams in a string.

def find_all_anagrams(text, pattern):
    pattern_length = len(pattern)
    text_length = len(text)
    result = []

    pattern_hash = get_hash(pattern, pattern_length)

    for i in range(text_length - pattern_length + 1):
        if get_hash(text[i:i+pattern_length], pattern_length) == pattern_hash:
            result.append(i)

    return result

def get_hash(str, length):
    hash_value = 0
    p = 31
    for i in range(length):
        hash_value = hash_value + ord(str[i]) * p
        p = p * 31
    return hash_value

text = input("Enter the text string: ")
pattern = input("Enter the pattern string: ")
print(find_all_anagrams(text, pattern))

In this code, the `find_all_anagrams` function generates the hash values of both the pattern and the text. It then iterates over the text, and for each substring, it checks if the substring's hash matches the pattern's hash. If they match, it appends the index to the result list.

The `get_hash` function generates a hash value for a given string. It uses the formula `hash_value = hash_value + ord(str[i]) * p` where `p` is a prime number. This is used to prevent hash collision.

The code then reads the text and pattern from the user, and prints the result of `find_all_anagrams` function.