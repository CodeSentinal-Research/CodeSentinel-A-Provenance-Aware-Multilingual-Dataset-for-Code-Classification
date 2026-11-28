Here is the Python code for the problem:

def digit_frequency_counter(N):
    freqs = [0] * 10
    
    str_N = str(N)
    
    for digit_str in str_N:
        digit = int(digit_str)
        
        freqs[digit] += 1
    
    return freqs

print(digit_frequency_counter(1234567890))

This code will print the ten integers representing the frequencies of digits 0 through 9 for the number 1234567890.

The `digit_frequency_counter` function works by first initializing a list of 10 zeros. It then converts the input number into a string and loops through each digit in the string. For each digit, it converts the digit back to an integer and increments the corresponding index in the `freqs` list. Finally, it returns the `freqs` list, which contains the frequencies of all digits from 0 to 9.