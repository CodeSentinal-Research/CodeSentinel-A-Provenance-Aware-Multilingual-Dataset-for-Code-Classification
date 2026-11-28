Here is a Python code that solves the problem:

def countOfAtoms(formula):
    from collections import Counter
    stack = [Counter()] * 26
    index = 26
    res = []
    i = 0
    while i < len(formula):
        if formula[i] == '(':
            stack.append(Counter())
            i += 1
        elif formula[i].isdigit():
            k = 0
            while i < len(formula) and formula[i].isdigit():
                k = k * 10 + int(formula[i])
                i += 1
            k -= 1
            for j in range(26):
                stack[j] += stack[index].most_common()[j][1]
            i -= 1
        elif formula[i].isupper():
            index = ord(formula[i]) - 26
            i += 1
        else:
            for j in range(ord(formula[i]) - 26, 26):
                stack[j] += stack[index].most_common()[j][1]
            i += 1
    for count in stack[26].most_common():
        res.append(count[0])
    return ''.join(res[i] + str(stack[i + 26].most_common()[0][1]) for i in range(26)) + formula[i + 1:]

def main():
    formula = input("Enter the chemical formula: ")
    print(countOfAtoms(formula))

if __name__ == "__main__":
    main()

In this code, we use a stack of Counters to keep track of the atom counts. The `Counter` class in Python is a dictionary subclass for counting hashable objects. We use it to keep track of the count of each atom in the formula.

The main function gets the input formula from the user, calls the `countOfAtoms` function with this formula as argument, and prints the result.

The `countOfAtoms` function iterates through the formula. When it encounters an uppercase letter, it sets the index of the Counter based on this letter (since the Counter is shared for all atoms with the same initial letter). When it encounters a number, it multiplies the count by the number and adds it to the Counter. When it encounters a lowercase letter, it adds the count of this atom to the Counter of the letter it corresponds to. When it encounters a closing parenthesis, it pops the Counter from the stack and multiplies it by the count. When it encounters a lowercase letter in the closing parenthesis, it also adds the count of this atom to the Counter of the letter it corresponds to.

The last step in the function is to get the counts of the atoms in lexicographical order. We iterate over all atoms in the Counter (excluding the stack's counters) and append the count and the atom's name to the result list. We then join the result list into a string and return it.