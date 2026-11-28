def minBoatsToSavePeople():
    n, limit = map(int, input().split())
    people = sorted(map(int, input().split()))
    left, right = 0, n - 1
    boats = 0
    while left <= right:
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
            boats += 1
        else:
            right -= 1
            boats += 1
    print(boats)

if __name__ == "__main__":
    minBoatsToSavePeople()