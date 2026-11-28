def find_largest_element(array):
    return max(array)

if __name__ == "__main__":
    N = int(input().strip())
    array = list(map(int, input().strip().split()))
    print(find_largest_element(array))