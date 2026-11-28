def solve(s):
    vowels = set("aeiou")
    count = 0
    for i in range(len(s)):
        if s[i] in vowels:
            count += 1
            if i + 1 < len(s) and s[i + 1] in vowels:
                count += 1
                if i + 2 < len(s) and s[i + 2] in vowels:
                    count += 1
    return count

def main():
    s = input()
    print(solve(s))

if __name__ == "__main__":
    main()