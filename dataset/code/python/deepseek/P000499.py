def make_great(s):
    i = 0
    res = ''
    while i < len(s):
        if i < len(s)-1 and s[i].lower() == s[i+1].lower():
            i += 1
        else:
            res += s[i]
        i += 1
    return res

def main():
    s = input("Enter a string: ")
    print(make_great(s))

if __name__ == "__main__":
    main()