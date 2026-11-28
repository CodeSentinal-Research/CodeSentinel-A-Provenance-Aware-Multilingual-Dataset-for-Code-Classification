Sure, here is the Python code:

def split_string_into_fibonacci_sequence(s):
    nums = [int(n) for n in s.split()]
    if len(nums) < 3:
        return 'IMPOSSIBLE'
    fib_seq = []
    while len(fib_seq) < len(nums):
        if len(fib_seq) == 0 or len(fib_seq) == 1:
            fib_seq.append(nums[0])
        else:
            fib_seq.append(fib_seq[-1] + fib_seq[-2])
        if fib_seq[-1] > (2**31) - 1 or fib_seq[-1] < -(2**31):
            return 'IMPOSSIBLE'
    return fib_seq

def main():
    s = input()
    result = split_string_into_fibonacci_sequence(s)
    if isinstance(result, str) and result == 'IMPOSSIBLE':
        print('IMPOSSIBLE')
    else:
        print(' '.join(map(str, result)))

if __name__ == '__main__':
    main()

In this code, we first split the input string into a list of integers. Then we generate the Fibonacci sequence by adding the last two numbers in the sequence. We check if the last number of the sequence overflows, and if so, we return 'IMPOSSIBLE'. If not, we add the last number to the sequence and continue until the sequence has the required length.