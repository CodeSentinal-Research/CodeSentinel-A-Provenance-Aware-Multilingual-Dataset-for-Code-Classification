Here is the code for the problem:

def removeDuplicateLetters(s):
    count = [0]*256
    for char in s:
        count[ord(char)] += 1

    res = []
    for char in s:
        if count[ord(char)] and res[-1] != char:
            res.append(char)
            count[ord(char)] -= 1

    return ''.join(res)

def main():
    s = input("Enter a string: ")
    print("Smallest lexicographically valid string: ", removeDuplicateLetters(s))

if __name__ == "__main__":
    main()

This program uses a similar approach to the problem "Remove Duplicate Letters", but instead of using a stack to store the characters, it uses a list to store the result. It also uses a count array to count the frequency of each character, and it checks for the occurrence of a character in the result.