Here is the Python code for generating all permutations of a string:

def permute(data, i, length):
    if i==length:
        print(''.join(data))
    else:
        for j in range(i,length):
            data[i], data[j] = data[j], data[i]
            permute(data, i+1, length)
            data[i], data[j] = data[j], data[i]  

def main():
    s = input("Enter the string: ")
    s = list(s)
    permute(s, 0, len(s))

if __name__ == "__main__":
    main()
In this code, the `permute` function generates all permutations of the string using recursion. It takes four arguments: `data`, `i` (the current index), and `length` (the length of the string).

In the `main` function, it takes the input string and converts it into a list of characters. Then it calls the `permute` function with these arguments.

The `permute` function works by swapping each character in the list with every other character in the list and recursively calling itself. It does this until it has gone through all the characters in the list.