def print_alphabet():
    for char in range(ord('Z'), ord('A') - 1, -1):
        print(chr(char), end=' ')

print_alphabet()