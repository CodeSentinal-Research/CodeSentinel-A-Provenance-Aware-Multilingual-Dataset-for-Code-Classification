def average_of_array_elements():
    N = int(input())
    array = list(map(int, input().split()))
    average = sum(array) / len(array)
    print(average)

if __name__ == "__main__":
    average_of_array_elements()