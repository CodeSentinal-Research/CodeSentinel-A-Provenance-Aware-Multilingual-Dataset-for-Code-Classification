Here is a simple python code snippet that solves the problem:

def remove_vowels(S):
    vowels = "aeiouAEIOU"
    S = ''.join([char for char in S if char not in vowels])
    return S

S = input()
print(remove_vowels(S))

In this code, the function `remove_vowels` takes a string `S` as an argument and uses a list comprehension to create a new string, where each character is only included if it is not a vowel. The function then returns the new string.

In the main part of the code, the user is asked to input a string. The function `remove_vowels` is then called with the user's input. The result is printed out.