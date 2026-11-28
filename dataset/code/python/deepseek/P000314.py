Here is the Python code for the given problem:

def convertToTitle(columnNumber):
    res = ''
    while columnNumber > 0:
        columnNumber -= 1
        res = chr(columnNumber % 26 + ord('A')) + res
        columnNumber //= 26
    return res

print(convertToTitle(28))  
print(convertToTitle(52))  

The function `convertToTitle(columnNumber)` converts a given column number to its corresponding Excel column title. It works by performing the division and modulus operations in a while loop until the column number is 0. Inside the loop, it uses the `chr` function to get the ASCII character of the current column letter and concatenates it to the result string. The loop then continues by dividing the column number by 26 (the number of columns in an Excel column) and carrying over the remainder, which is what makes up the current letter in the Excel column title.