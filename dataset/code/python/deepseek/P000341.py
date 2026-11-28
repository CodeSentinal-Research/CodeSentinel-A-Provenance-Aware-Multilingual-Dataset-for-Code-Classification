Here is the Python code to solve the problem:

def word_equals_sum(firstWord, secondWord, targetWord):
    sum_words = int(firstWord) + int(secondWord) + int(targetWord)

    if sum_words == int(targetWord):
        print("Yes")
    else:
        print("No")

word_equals_sum('1', '2', '3')

In this code, the function `word_equals_sum` is defined to check if the numerical value of a word equals the sum of the numerical values of two other words. It uses Python's built-in `int` function to convert the words to integers, and then checks if the sum of the integers equals the target word's integer value.

The `word_equals_sum` function is then tested with the input ('1', '2', '3'), which should print 'Yes' because the sum of '1', '2', and '3' is 6, which is equal to the target word's integer value (3).