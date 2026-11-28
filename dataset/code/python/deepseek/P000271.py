Here is a simple Python program that checks if one string is a rotation of another.

def is_rotation(s1, s2):
    if len(s1) != len(s2):
        return False
    else:
        s1_twice = s1 + s1
        if s2 in s1_twice:
            return True
        else:
            return False

def main():
    s1 = input("Enter the first string: ")
    s2 = input("Enter the second string: ")
    if is_rotation(s1, s2):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

In this program, the function `is_rotation` checks if the second string is a rotation of the first string. It first checks if the lengths of the two strings are equal, and if they are, it checks if the second string is a substring of the first string concatenated with itself. If it is, the function returns `True`; otherwise, it returns `False`.

The `main` function is the entry point of the program. It reads two strings from the user and prints whether the first string is a rotation of the second string.