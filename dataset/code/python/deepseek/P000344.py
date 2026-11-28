def count_prefixes(words, s):
    count = 0
    for word in words:
        if s in word:
            count += 1
    return count

def main():
    words = input("Enter a list of words separated by space: ").split()
    s = input("Enter a string: ")
    print("Number of prefixes: ", count_prefixes(words, s))

if __name__ == "__main__":
    main()