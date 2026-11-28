from typing import List

class Solution:
    def inversionCount(self, arr: List[int], n: int) -> int:
        def merge_sort(l, r):
            """Sorts the input array into ordered sequence."""
            if l >= r:
                return 0
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            inv = merge_sort(l, mid) + merge_sort(mid + 1, r)

            temp = []
            i, j = l, mid + 1
            while i <= mid and j <= r:
                if arr[i] <= arr[j]:
                    temp.append(arr[i])
                    i += 1
                else:
                    temp.append(arr[j])
                    inv += (mid - i + 1)
                    j += 1

            while i <= mid:
                temp.append(arr[i])
                i += 1
            while j <= r:
                temp.append(arr[j])
                j += 1

            for k in range(len(temp)):
                arr[l + k] = temp[k]

            return inv

        return merge_sort(0, n - 1)