def remove_duplicates(S, K):
    stack = []
    for ch in S:
        if stack and stack[-1] == ch:
            stack[-1] += 1
            if stack[-1] == K:
                stack.pop()
        else:
            stack.append(ch)
    return ''.join(stack)

def main():
    S = input('Enter the string: ')
    K = int(input('Enter the integer K: '))
    print(remove_duplicates(S, K))

if __name__ == "__main__":
    main()