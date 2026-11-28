Sure, here is the Python code for the problem:

def maxScore(S):
    S_0 = S[0:S.index('0')]
    S_1 = S[S.index('1')+1:]

    count_0 = S_0.count('0')
    count_1 = S_0.count('1')

    count_0_1 = S_1.count('0') + S_1.count('1')

    return max(count_0 + count_0_1, count_1 + count_0_1)

if __name__ == "__main__":
    S = input()
    print(maxScore(S))
In this code, we first split the string into two parts based on the first occurrence of '0' and '1' respectively. Then, we count the number of '0's and '1's in each part. We return the maximum score as the sum of the maximum count of '0's and '1's in each part plus the sum of the maximum count of '0's and '1's in both parts.