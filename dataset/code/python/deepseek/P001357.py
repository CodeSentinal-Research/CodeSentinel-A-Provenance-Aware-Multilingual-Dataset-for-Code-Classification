def isAdditiveNumber(s):
    def isValid(i, j):
        s1, s2 = s[i:j], s[j:]
        if s2 and s2[0] == '0' and len(s2) > 1 or s2 > '2' * len(s2):
            return False
        num1, num2 = int(s1), int(s2)
        while i + j < len(s) and num1 <= num2:
            s1, s2 = s2, s1 + s2
            num1, num2 = num2, num1 + num2
            if s2 not in s[i:j + len(s2)] or num2 > '2' * len(s2):
                return False
        return num1 == num2

    s = s.lstrip('0')
    n = len(s)
    for i in range(1, n - 1):
        for j in range(i + 1, n):
            if isValid(i, j):
                return 'YES'
    return 'NO'

def main():
    s = input()
    print(isAdditiveNumber(s))

if __name__ == '__main__':
    main()
This python code will take the numeric string as input and check if it forms an additive sequence or not. The `isAdditiveNumber` function implements a brute force approach to check for all possible combinations of additive numbers. The `isValid` function checks if a given substring `s1` and `s2` forms a valid additive sequence.