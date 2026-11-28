def convert_lowercase_to_uppercase(c):
    if 'a' <= c <= 'z':
        return chr(ord(c) - ord('a') + ord('A'))
    else:
        return c

def main():
    c = input("Enter a lowercase letter: ")
    print("The uppercase equivalent is: ", convert_lowercase_to_uppercase(c))

if __name__ == "__main__":
    main()