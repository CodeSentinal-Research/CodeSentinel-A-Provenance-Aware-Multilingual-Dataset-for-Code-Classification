def count_subarrays(arr, k):
    n = len(arr)
    dist_counts = [0] * (n + 1)
    dist_counts[0] = 1
    left, right = 0, 0
    valid_subarrays = 0

    while right < n:
        if arr[right] not in dist_counts[left:right]:
            dist_counts[right] = dist_counts[right - 1] if right > 0 else 0
            dist_counts[right] += dist_counts[right - 1] if right > 0 else 0
            dist_counts[right] += 1
        else:
            dist_counts[right] = dist_counts[right - 1] if right > 0 else 0
            dist