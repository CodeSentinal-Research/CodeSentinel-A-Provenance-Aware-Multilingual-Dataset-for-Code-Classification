def find_longest_word(s, dictionary):
    dictionary.sort(key=len, reverse=True)

    for word in dictionary:
        if set(word) <= set(s):
            return word

    return None

def main():
    s = input()
    dictionary = input().split()
    print(find_longest_word(s, dictionary))

if __name__ == "__main__":
    main()