def reverse_prefix(s: str, c: str) -> str:
    index = s.find(c)
    if index != -1:
        s = s[:index+1][::-1] + s[index+1:]
    return s

def main():
    s = input()
    c = input()
    print(reverse_prefix(s, c))

if __name__ == "__main__":
    main()