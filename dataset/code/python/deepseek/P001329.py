def generate_permutations(arr, index):
    if index == len(arr):
        print(arr)
    for i in range(index, len(arr)):
        if is_swapped(arr, index, i):
            arr[index], arr[i] = arr[i], arr[index]
            generate_permutations(arr, index + 1)
            arr[index], arr[i] = arr[i], arr[index]  

def is_swapped(arr, index, i):
    if index == i:
        return False
    return arr[index] == arr[i]

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    generate_permutations(arr, 0)

if __name__ == '__main__':
    main()