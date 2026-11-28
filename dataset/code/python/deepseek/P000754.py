Here is the Python code for the problem:

import itertools

def generate_case_permutations(s):
    permutations = set()
    for p in itertools.permutations(s, len(s)):
        if ''.join(p) == s:
            continue
        permutations.add(''.join(p))
    
    permutations = sorted(list(permutations))
    
    return permutations

def main():
    s = input("Enter the string: ")
    permutations = generate_case_permutations(s)
    
    for permutation in permutations:
        print(permutation)

if __name__ == "__main__":
    main()

You can run this code and input a string when prompted. It will print all case permutations of the input string, sorted lexicographically. Note that this program considers uppercase and lowercase letters as different characters, so it will print a permutation of the same word if the same letter is capitalized in the original string.