def length_of_longest_substring(s: str) -> int:
    dict_chars = {}
    start = 0
    max_len = 0

    for i, char in enumerate(s):
        if char in dict_chars and start <= dict_chars[char]:
            start = dict_chars[char] + 1
        else:
            max_len = max(max_len, i - start + 1)

        dict_chars[char] = i

    return max_len

while True:
    user_input = input('Enter a string (or "quit" to exit): ')
    if user_input.lower() == 'quit':
        break
    else:
        print(length_of_longest_substring(user_input))