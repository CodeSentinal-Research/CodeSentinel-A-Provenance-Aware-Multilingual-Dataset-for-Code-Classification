def minParentheses(s):
    left, right, balance = 0, 0, 0
    for char in s:
        if char == '(':
            left += 1
            balance += 1
        else:
            right += 1
            balance -= 1
    return left + right + balance

def main():
    s = input().strip()
    print(minParentheses(s))

if __name__ == "__main__":
    main()