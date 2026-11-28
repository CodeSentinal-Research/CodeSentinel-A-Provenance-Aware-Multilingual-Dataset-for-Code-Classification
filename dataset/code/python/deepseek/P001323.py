def find_combinations(candidates, target):
    def backtrack(remain, comb, start):
        if remain == 0:
            result.append(list(comb))
            return
        elif remain < 0:
            return
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            comb.append(candidates[i])
            backtrack(remain - candidates[i], comb, i + 1)
            comb.pop()

    result = []
    candidates.sort()
    backtrack(target, [], 0)
    return result


def main():
    N, Target = map(int, input().split())
    candidates = list(map(int, input().split()))
    print(find_combinations(candidates, Target))


if __name__ == "__main__":
    main()