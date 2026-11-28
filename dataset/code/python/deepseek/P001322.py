def combinationSum(candidates, target):
    def dfs(candidates, target, start, path, res):
        if target < 0:
            return  
        if target == 0:
            res.append(path)
            return 
        for i in range(start, len(candidates)):
            dfs(candidates, target-candidates[i], i, path+[candidates[i]], res)

    res = []
    candidates.sort()
    dfs(candidates, target, 0, [], res)
    return res

The above code provides a Python solution for the Combination Sum problem. The main function calls a recursive DFS (Depth First Search) function to find all the combinations. The DFS function is defined inside the main function and takes four parameters: the candidate list, the target sum, the starting index of the current combination, the current combination, and the result list. 

The main function is defined as follows:

def main():
    N = int(input().strip())
    target = int(input().strip())
    numbers = list(map(int, input().strip().split()))[:N]
    print(combinationSum(numbers, target))

if __name__ == "__main__":
    main()

The `main` function reads the input and calls the `combinationSum` function to get the result. The input is a list of numbers and a target sum. The numbers are sorted before passing them to the `combinationSum` function. The `combinationSum` function prints the result and the `main` function is the entry point of the program.