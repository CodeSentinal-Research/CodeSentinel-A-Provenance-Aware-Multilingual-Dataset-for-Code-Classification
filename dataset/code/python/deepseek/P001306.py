Here is the Python code for the problem:

def merge_files():
    N = int(input().strip())
    file_sizes = list(map(int, input().strip().split()))

    total_cost = 0
    file_sizes.sort()

    for i in range(N // 2):
        total_cost += file_sizes[i] + file_sizes[N - i - 1]

    print(total_cost)


if __name__ == "__main__":
    merge_files()

This Python program reads the number of files and their sizes from the input. It then sorts the file sizes in ascending order. It then iterates over the sorted file sizes, adding the sum of each pair of files to the total cost. The final total cost is printed out at the end.