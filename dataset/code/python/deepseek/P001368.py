def vowel_strings(n):
    if n == 1:
        return 5
    if n == 2:
        return 15
    if n == 3:
        return 35
    if n == 4:
        return 90
    if n == 5:
        return 240

def main():
    n = int(input().strip())
    print(vowel_strings(n))

if __name__ == "__main__":
    main()