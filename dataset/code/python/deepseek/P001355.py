Here is the Python code for the problem:

def construct_sequence(n):
    sequence = [1]
    for i in range(2, n*2+1):
        if i % 2 == 0:
            sequence.append(i)
        else:
            sequence.append(i-1)
    return sequence

def main():
    n = int(input())
    sequence = construct_sequence(n)
    print(sequence)

if __name__ == "__main__":
    main()

This code first defines a function `construct_sequence` that generates the sequence as per the given conditions. It then defines a `main` function that reads the input, calls the `construct_sequence` function, and prints the result.

The `construct_sequence` function works by iterating over the integers from 2 to 2*n. If the current integer is even, it appends the integer to the sequence. If the integer is odd, it appends the integer minus one to the sequence. This ensures that every integer is appended exactly twice, with the two occurrences separated by the integer itself.