def reverse_words(s):
    return ' '.join(s.split()[::-1])

def main():
    s = input("Enter a sentence: ")
    print(reverse_words(s))

if __name__ == "__main__":
    main()