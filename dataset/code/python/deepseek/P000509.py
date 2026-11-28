def clear_digits(s):
    stack = []
    for c in s:
        if c.isalpha():
            stack.append(c)
        elif c.isdigit():
            if stack:
                stack.pop()
    return ''.join(stack)

def main():
    s = input()
    print(clear_digits(s))

if __name__ == "__main__":
    main()