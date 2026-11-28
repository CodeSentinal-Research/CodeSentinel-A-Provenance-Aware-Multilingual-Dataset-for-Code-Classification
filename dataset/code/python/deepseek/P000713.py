Here is the Python code for the problem:

def combinationSum2(candidates, target):
    def backtrack(candidates, target, start, path, results):
        if target < 0 or len(path) > target:
            return 
        if target == 0:
            results.append(path)
            return
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            backtrack(candidates, target - candidates[i], i + 1, path + [candidates[i]], results)

    results = []
    candidates.sort()
    backtrack(candidates, target, 0, [], results)
    return results

And the main function:

def main():
    candidates = list(map(int, input('Enter the array of candidates: ').split()))
    target = int(input('Enter the target: '))
    print(combinationSum2(candidates, target))

if __name__ == '__main__':
    main()

You can run this Python program, then input your candidates and target. It will print all unique valid combinations.