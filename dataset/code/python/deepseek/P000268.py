Here is a Python code that fulfills the problem requirements:

def count_words(s):
    words = s.split()
    return len(words)

if __name__ == "__main__":
    s = input()
    print(count_words(s))

In this code, we first define a function `count_words` that splits the input string into words and then returns the count of the words. Then we check if this function is run as a script. If it is, we ask the user for input and print the number of words in the input string.