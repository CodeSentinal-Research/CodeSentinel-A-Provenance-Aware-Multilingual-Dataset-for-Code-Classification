def minLength(s: str):
    while len(s) > 0 and len(s) > 1 and s[0] == s[-1]:
        s = s[1:-1]
    return len(s)

def main():
    s = input()
    print(minLength(s))

if __name__ == "__main__":
    main()