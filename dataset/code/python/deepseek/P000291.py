Here is the Python code:

def check_permutation(S1, S2):
    if sorted(S1) == sorted(S2):
        return "Yes"
    else:
        return "No"

S1 = input("Enter the first string: ")
S2 = input("Enter the second string: ")

print(check_permutation(S1, S2))

This code firstly takes two strings from the user input, then it calls the function `check_permutation` that checks whether the first string is a permutation of the second string. If it is, it returns "Yes", otherwise it returns "No". The `sorted` function is used to sort the characters in the strings so that they can be compared to each other.