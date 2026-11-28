def combinationSum(candidates, target):
    def backtrack(remain, comb, start):
        if remain == 0:
            result.append(list(comb))
            return
        elif remain < 0:
            return
        for i in range(start, len(candidates)):
            comb.append(candidates[i])
            backtrack(remain - candidates[i], comb, i)
            comb.pop()

    result = []
    backtrack(target, [], 0)
    return result