def find_element(array):
    for element in array:
        if array.count(element) % 2 == 1:
            return element
    return None

def main():
    N = int(input())
    array = list(map(int, input().split()))
    result = find_element(array)
    if result is not None:
        print(result)
    else:
        print("No element with odd occurrence")

if __name__ == "__main__":
    main()