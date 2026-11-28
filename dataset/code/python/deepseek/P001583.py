def count_subarrays(nums, k):
    from collections import deque
    left, right, distinct = 0, 0, set()
    count, total = 0, 0
    queue = deque()
    
    while right < len(nums):
        if nums[right] not in distinct:
            distinct.add(nums[right])
            queue.append(right)
            
        if len(distinct) == k:
            while queue[0] < right:
                left = queue.popleft()
                if nums[left] not in distinct:
                    distinct.remove(nums[left])
                
            total += len(queue)
            count += 1
            
        right += 1

    return count

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_subarrays(nums, k))

if __name__ == "__main__":
    main()