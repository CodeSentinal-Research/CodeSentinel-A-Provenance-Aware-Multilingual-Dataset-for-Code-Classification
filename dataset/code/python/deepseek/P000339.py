def check_halves_alike(s):
    s1 = s[:len(s)//2]
    s2 = s[len(s)//2:]
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    count1 = 0
    count2 = 0
    for c1, c2 in zip(s1, s2):
        if c1 in vowels:
            count1 += 1
        if c2 in vowels:
            count2 += 1
    return 'Yes' if count1 == count2 else 'No'

def main():
    s = input()
    print(check_halves_alike(s))

if __name__ == "__main__":
    main()