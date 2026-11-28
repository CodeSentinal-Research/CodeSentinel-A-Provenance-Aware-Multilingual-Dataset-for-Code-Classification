Here is the Python code:

def max_balloons(s):
    return min(s.count(c) // 2 for c in 'balloon')

def main():
    s = input()
    print(max_balloons(s))

if __name__ == "__main__":
    main()

This program first counts the number of times each character appears in the string, and then finds the minimum of these counts (since you can't have more instances of 'balloon' than there are characters in the string). The main function reads an input string, calls the `max_balloons` function with this string, and prints the result.