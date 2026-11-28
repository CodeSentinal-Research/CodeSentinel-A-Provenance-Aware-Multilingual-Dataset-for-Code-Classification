def minimum_swaps(string: str):
    stack = []
    for s in string:
        if s == '[':
            stack.append(s)
        else:
            if len(stack) == 0:
                stack.append(s)
            else:
                stack.pop()
    return len(stack)

def main():
    string = input()
    print(minimum_swaps(string))

if __name__ == '__main__':
    main()