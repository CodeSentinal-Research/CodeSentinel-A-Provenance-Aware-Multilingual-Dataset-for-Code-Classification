Here is a Python solution that uses a sliding window approach to solve the problem:

def maxFruits(arr):
    left = 0
    right = 0
    max_fruits = 0
    fruit_dict = {}
    
    while right < len(arr):
        fruit_dict[arr[right]] = fruit_dict.get(arr[right], 0) + 1
        while len(fruit_dict) > 2:
            fruit_dict[arr[left]] = fruit_dict[arr[left]] - 1
            if fruit_dict[arr[left]] == 0:
                del fruit_dict[arr[left]]
            left += 1
        max_fruits = max(max_fruits, right - left + 1)
        right += 1
    
    return max_fruits

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(maxFruits(arr))

if __name__ == "__main__":
    main()

This code works by iterating through the array, keeping track of the number of each fruit type in a dictionary. It then tries to maximize the number of fruits in the window by moving the right pointer. If there are more than two types of fruits in the window, it moves the left pointer to the right. The maximum number of fruits in the window is tracked and updated as it moves. The main function reads the number of fruits and the array of fruits from standard input, then prints the maximum number of fruits.