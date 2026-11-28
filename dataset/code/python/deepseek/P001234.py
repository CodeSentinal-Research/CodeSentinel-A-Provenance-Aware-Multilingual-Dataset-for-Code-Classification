def min_platforms(n, arr, dep):
    arr.sort()
    dep.sort()

    platforms = 1
    max_platform = arr[0]

    i = 1
    j = 0

    while i < len(arr) and j < len(dep):
        if arr[i] < dep[j]:
            platforms += 1
            max_platform = max(max_platform, arr[i])
            i += 1
        else:
            platforms += 1
            max_platform = max(max_platform, dep[j])
            j += 1

    return platforms, max_platform

def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    dep = [int(x) for x in input().split()]
    platforms, max_platform = min_platforms(n, arr, dep)
    print(platforms, max_platform)

if __name__ == "__main__":
    main()