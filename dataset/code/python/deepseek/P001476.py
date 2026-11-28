Here is a Python solution for the problem. This solution uses the two-pointer technique to find the maximum bar in the left and right sides. Then, it calculates the area of water that can be stored with each bar.

def trap_rain_water(arr):
    if not arr or len(arr) == 0:
        return 0

    max_left = arr[0]
    max_right = arr[-1]
    left = 0
    right = len(arr) - 1
    total = 0

    while left < right:
        if max_left < max_right:
            max_left_temp = max_left
            while arr[left] < max_left_temp:
                total += max_left_temp - arr[left]
                left += 1
            max_left = max_left_temp + 1
        else:
            max_right_temp = max_right
            while arr[right] < max_right_temp:
                total += max_right_temp - arr[right]
                right -= 1
            max_right = max_right_temp + 1

    return total


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(trap_rain_water(arr))


if __name__ == '__main__':
    main()

This program first reads the number of bars and the heights of the bars from the input. It then calls the `trap_rain_water` function with these inputs and prints the result.