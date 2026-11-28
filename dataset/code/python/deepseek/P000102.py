def find_smallest_element(array):
    return min(array)

def main():
    n = int(input())
    array = list(map(int, input().split()))
    print(find_smallest_element(array))

if __name__ == "__main__":
    main()