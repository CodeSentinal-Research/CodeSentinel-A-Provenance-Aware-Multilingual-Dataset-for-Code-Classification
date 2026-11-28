import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums1 = list(map(int, input_data[idx:idx+n])); idx += n
    nums2 = list(map(int, input_data[idx:idx+m])); idx += m
    
    def max_subsequence(nums, length):
        drop = len(nums) - length
        stack = []
        for num in nums:
            while drop > 0 and stack and stack[-1] < num:
                stack.pop()
                drop -= 1
            stack.append(num)
        return stack[:length]
        
    def merge(seq1, seq2):
        result = []
        while seq1 or seq2:
            if seq1 > seq2:
                result.append(seq1.pop(0))
            else:
                result.append(seq2.pop(0))
        return result
        
    max_num = []
    for i in range(max(0, k - m), min(k, n) + 1):
        seq1 = max_subsequence(nums1, i)
        seq2 = max_subsequence(nums2, k - i)
        merged = merge(seq1, seq2)
        if merged > max_num:
            max_num = merged
            
    print("".join(map(str, max_num)))

if __name__ == "__main__":
    solve()

