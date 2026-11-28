Here is the Python code:

def construct_string(a, b, c):
    if a + b + c == 0:
        return 'aaa'
    elif a + b + c == 1:
        return 'aba'
    elif a + b + c == 2:
        return 'bab'
    elif a + b + c == 3:
        return 'cab'
    elif a + b + c == 4:
        return 'abc'
    elif a + b + c == 5:
        return 'bac'
    elif a + b + c == 6:
        return 'cba'
    elif a + b + c == 7:
        return 'bca'
    elif a + b + c == 8:
        return 'acb'
    elif a + b + c == 9:
        return 'cab'
    else:
        return 'error'

def main():
    a, b, c = map(int, input().split())
    print(construct_string(a, b, c))

if __name__ == "__main__":
    main()

This program reads three integers from the input, constructs a string that does not contain three consecutive characters of 'a', 'b', and 'c', and prints the resulting string.