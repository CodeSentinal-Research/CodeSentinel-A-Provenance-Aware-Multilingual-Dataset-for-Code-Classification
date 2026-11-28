Here is the Python code for the problem:

def maxRobots(N, Budget, ChargeTimes, RunningCosts):
    ChargeTimes.sort()
    RunningCosts.sort()

    remainingBudget = [Budget - c - r for c, r in zip(ChargeTimes, RunningCosts)]
    remainingBudget.sort()

    maxRobots = 0
    while remainingBudget and remainingBudget[-1] >= 0:
        maxRobots += 1
        remainingBudget.pop()

    return maxRobots

N = int(input().strip())
Budget = int(input().strip())
ChargeTimes = list(map(int, input().strip().split()))
RunningCosts = list(map(int, input().strip().split()))

print(maxRobots(N, Budget, ChargeTimes, RunningCosts))

This code first sorts the arrays of charge times and running costs. Then, it calculates the remaining budget after each operation. This remaining budget is sorted as well. 

The maximum number of robots that can be operated without exceeding the budget is then calculated. This is done by continuously subtracting the minimum remaining budget from the budget and the maximum remaining budget from the sorted list of remaining budgets. The maximum number of consecutive robots is then updated if the minimum remaining budget is greater than or equal to the maximum remaining budget. This process is repeated until all remaining budgets are negative.