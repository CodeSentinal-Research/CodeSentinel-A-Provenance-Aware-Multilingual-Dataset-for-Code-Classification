Here is the Python code for the given problem:

def check_vowel_or_consonant(c):
    vowels = 'aeiouAEIOU'
    if c in vowels:
        print('Vowel')
    else:
        print('Consonant')

c = input("Enter a character: ")
check_vowel_or_consonant(c)

This code will take the input character and check whether it is a vowel or a consonant. If the character is a vowel, it will print 'Vowel', otherwise it will print 'Consonant'.