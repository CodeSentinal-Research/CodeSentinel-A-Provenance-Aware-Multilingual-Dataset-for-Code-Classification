Sure, here is the Python code for generating all permutations of a list of distinct integers.

def generate_permutations(arr, i, length):
    if i == length:
        print(' '.join(map(str, arr)))
    else:
        for j in range(i, length):
            arr[i], arr[j] = arr[j], arr[i]
            generate_permutations(arr, i + 1, length)
            arr[i], arr[j] = arr[j], arr[i]  

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    generate_permutations(arr, 0, n)

if __name__ == "__main__":
    main()
This program first reads the number of elements in the array and then the elements themselves. It then calls the `generate_permutations` function to generate and print all permutations. The `generate_permutations` function uses recursion to generate all permutations. It takes an array and two indices as input. If the index is equal to the length of the array, it means we have generated a permutation, so it prints the permutation. If not, it generates all permutations by swapping elements at indices i and i+1 to all indices larger than i. Finally, the `main` function reads the input and calls the `generate_permutations` function.