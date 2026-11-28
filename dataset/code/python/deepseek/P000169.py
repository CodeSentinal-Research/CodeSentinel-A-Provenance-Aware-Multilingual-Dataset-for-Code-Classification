def find_first_repeating_element():
    n = int(input())
    arr = list(map(int, input().split()))

    visited = set()
    for i in range(n):
        if arr[i] in visited:
            return arr[i]
        else:
            visited.add(arr[i])

    return -1

if __name__ == "__main__":
    print(find_first_repeating_element())