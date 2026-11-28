Here is the Python code for the problem:

def sliding_window_median():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    def find_median(nums, K):
        window = sorted(nums[:K])
        medians = [window[K//2]]

        for i in range(K, len(nums)):
            window.remove(nums[i-K])
            window.append(nums[i])
            medians.append(window[K//2])

        return medians

    print('\n'.join(map(str, find_median(nums, K))))


if __name__ == "__main__":
    sliding_window_median()

This program prompts the user to input the size of the array `N` and the window size `K`. It then prompts the user to input the array `N` integers. The function `find_median` computes the median of every contiguous subarray of size `K` by using a sliding window approach.

Note: The input data consists of two lines. The first line consists of two integers `N` and `K` separated by a space. The second line consists of `N` integers separated by a space.