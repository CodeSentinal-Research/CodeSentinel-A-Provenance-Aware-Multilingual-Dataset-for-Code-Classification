Here is the Python code to solve the problem:

def smallestInfiniteSet():
    nums = set(range(1, 2002))

    while nums:
        yield min(nums)
        nums.remove(min(nums))


def solve(ops):
    s = smallestInfiniteSet()
    for op in ops:
        if op == 'remove':
            print(next(s))
        elif op == 'add':
            num = int(op.split()[1])
            if num not in s:
                s.add(num)


if __name__ == "__main__":
    Q = int(input().strip())
    ops = [input().strip() for _ in range(Q)]
    solve(ops)

This code uses a generator function `smallestInfiniteSet()` to yield the smallest numbers in a set, and a function `solve()` to handle the operations. The `smallestInfiniteSet()` function starts with a set of numbers from 1 to 2002 and continuously removes and returns the smallest numbers. The `solve()` function reads the operations and performs them on the smallest numbers set.

Please note, you need to provide the operations to the `solve()` function in the format 'remove' or 'add'. For 'add', the number to add should follow.