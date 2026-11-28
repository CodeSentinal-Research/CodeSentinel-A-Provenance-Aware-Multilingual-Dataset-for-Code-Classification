def replace_digits(s):
    res = ''
    for char in s:
        if char.isdigit():
            res += chr(int(char) + 1)
        else:
            res += char
    return res

def main():
    s = input('Enter a string: ')
    print(replace_digits(s))

if __name__ == '__main__':
    main()