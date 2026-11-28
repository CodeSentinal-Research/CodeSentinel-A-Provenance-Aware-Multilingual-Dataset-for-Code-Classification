def remove_all_occurrences(s, c):
    return s.replace(c, '')

if __name__ == "__main__":
    s = input("Enter a string: ")
    c = input("Enter a character to remove: ")
    print(remove_all_occurrences(s, c))