def detect_capital(word):
    if word.isupper():
        print('Yes')
    else:
        print('No')

def main():
    word = input()
    detect_capital(word)

if __name__ == "__main__":
    main()