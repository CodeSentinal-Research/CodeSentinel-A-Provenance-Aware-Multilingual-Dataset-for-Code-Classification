def trapped_rain_water(heights):
    left, right = 0, len(heights) - 1
    max_left, max_right = 0, 0
    total = 0

    while left < right:
        if heights[left] < heights[right]:
            if heights[left] > max_left:
                max_left = heights[left]
            else:
                total += max_left - heights[left]
            left += 1
        else:
            if heights[right] > max_right:
                max_right = heights[right]
            else:
                total += max_right - heights[right]
            right -= 1

    return total

if __name__ == "__main__":
    n = int(input().strip())
    heights = list(map(int, input().strip().split()))
    print(trapped_rain_water(heights))