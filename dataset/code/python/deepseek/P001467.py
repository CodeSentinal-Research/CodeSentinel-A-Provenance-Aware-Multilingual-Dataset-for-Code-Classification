Here is the Python code:

def reverse_vowels(s):
    vowels = 'aeiouAEIOU'
    s = list(s)
    i, j = 0, len(s) - 1
    while i < j:
        if s[i] not in vowels:
            i += 1
        elif s[j] not in vowels:
            j -= 1
        else:
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
    return ''.join(s)

s = input()
print(reverse_vowels(s))

This code first reads a string as input. Then, it calls the `reverse_vowels` function, which modifies the string by reversing the vowels while leaving all other characters unchanged. The modified string is then printed.