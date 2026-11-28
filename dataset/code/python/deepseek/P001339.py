Here is the Python code for the problem:

def maxLength(N, strings):
    unique_chars = set()
    subsets = []

    for s in strings:
        curr_chars = []
        for c in s:
            if c not in unique_chars:
                curr_chars.append(c)
                unique_chars.add(c)
        if curr_chars:
            subsets.append(curr_chars)

    max_length = 0
    for subset in subsets:
        length = 0
        for c in subset:
            length += 1
        if length > max_length:
            max_length = length

    return max_length

And here is the main function and input handling:

def main():
    N = int(input().strip())
    strings = [input().strip() for _ in range(N)]
    print(maxLength(N, strings))

if __name__ == "__main__":
    main()

This code reads the number of strings and the strings themselves from the input, calls the `maxLength` function with these inputs, and then prints the result. The `main` function is the entry point of the program.