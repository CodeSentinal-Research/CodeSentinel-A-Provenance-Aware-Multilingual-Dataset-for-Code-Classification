def remove_adjacent(s):
    result = ""
    for char in s:
        if result.endswith(char):
            continue
        result += char
    return result

def main():
    s = input()
    while s:
        print(remove_adjacent(s))
        s = input()

if __name__ == "__main__":
    main()