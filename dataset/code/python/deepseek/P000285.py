def is_subsequence(s1, s2):
    if s1 in s2:
        return "Yes"
    else:
        return "No"

def main():
    s1 = input()
    s2 = input()
    print(is_subsequence(s1, s2))

if __name__ == "__main__":
    main()