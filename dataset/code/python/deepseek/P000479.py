def isValid(s):
    stack = []
    mapping = {")": "(", "]": "[", "}": "{"}

    for char in s:
        if char in mapping.values():
            stack.append(char)
        elif char in mapping.keys():
            if stack == [] or mapping[char] != stack.pop():
                return False
        else:
            return False
    return stack == []

def main():
    test_cases = ["()", "()[]{}", "(]", "{[]}", "({})"]
    for test_case in test_cases:
        print(f"{test_case} : {isValid(test_case)}")

if __name__ == "__main__":
    main()
This Python code uses a stack to solve the problem. The main function tests all possible inputs and prints the result for each one.