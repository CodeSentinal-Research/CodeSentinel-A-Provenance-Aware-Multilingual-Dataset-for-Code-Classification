def capitalize_first_letter(s):
    return ' '.join(word.capitalize() for word in s.split(' '))

def main():
    s = input("Enter a sentence: ")
    print(capitalize_first_letter(s))

if __name__ == "__main__":
    main()