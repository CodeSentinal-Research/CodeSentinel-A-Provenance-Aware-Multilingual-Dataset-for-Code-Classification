Here is a Python solution for the problem. The algorithm uses a simple encoding technique that converts each string into a list of ASCII values for its characters. Then it uses a simple decoding technique that converts the list of ASCII values back into the original strings.

def encode_strings(lst):
    encoded = []
    for s in lst:
        encoded.append([ord(c) for c in s])
    return encoded

def decode_strings(encoded_lst):
    decoded = []
    for ascii_lst in encoded_lst:
        decoded.append(''.join(chr(i) for i in ascii_lst))
    return decoded

def main():
    lst = ['hello', 'world']
    encoded = encode_strings(lst)
    print('Encoded:', encoded)
    decoded = decode_strings(encoded)
    print('Decoded:', decoded)

if __name__ == "__main__":
    main()

In this code:

- `encode_strings` function converts each string into a list of ASCII values for its characters.
- `decode_strings` function converts the list of ASCII values back into the original strings.
- `main` function handles the user input and output.
- The `if __name__ == "__main__"` part is a common idiom for main function.

Please note that this code only works for ASCII characters. If you want to encode and decode strings with unicode characters (like emojis), you would need to adjust the encoding and decoding methods.