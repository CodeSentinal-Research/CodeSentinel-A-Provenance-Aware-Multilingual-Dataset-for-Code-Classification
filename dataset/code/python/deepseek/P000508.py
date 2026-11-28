def visible_people(n, heights):
    result = [0]*n
    max_height = heights[n-1]
    result[n-1] = 1
    for i in range(n-2, -1, -1):
        if heights[i] > max_height:
            result[i] = 1
            max_height = heights[i]
        else:
            result[i] = result[i+1] + 1
    return result