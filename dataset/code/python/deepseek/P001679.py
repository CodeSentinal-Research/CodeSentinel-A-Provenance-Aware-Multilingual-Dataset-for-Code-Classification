Here is the Python code for the problem.

def find_max_sum_level(tree):
    level_sums = [0] * (len(tree) + 1)
    max_sum = float('-inf')
    min_level = float('inf')

    for i in range(len(tree)):
        if tree[i] is not None:
            level = i + 1
            level_sums[level] += tree[i]

            if level_sums[level] > max_sum:
                max_sum = level_sums[level]
                min_level = level
            elif level_sums[level] == max_sum:
                min_level = min(min_level, level)

    return min_level

def main():
    tree = list(map(int, input().split()))[1:]
    tree = [None] * (len(tree) - 1)

    print(find_max_sum_level(tree))

main()

In this code, we first initialize the sums at the level 1 and keep track of the max sum and the smallest level number with max sum. Then, for each node in the tree, we update the sum and the min level if the current sum is greater than max sum, or update min level if the current sum equals max sum.