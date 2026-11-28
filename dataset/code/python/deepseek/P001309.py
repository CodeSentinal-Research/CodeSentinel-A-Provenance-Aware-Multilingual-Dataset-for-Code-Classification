Here's the Python code that implements the solution for the problem.

def survival_on_island():
    S, N, M = map(int, input().split())
    
    if S > N:
        return -1

    purchase_days = S
    food_needed_per_day = S

    while True:
        if S + food_needed_per_day > N:
            break

        S += food_needed_per_day
        purchase_days += 1
        food_needed_per_day = min(food_needed_per_day + M, N - S + purchase_days)

    return purchase_days

print(survival_on_island())

This code first gets the input for S, N, and M. It then starts a loop that continues until the total purchase days exceed the survival days. In each iteration, it adds the food needed per day to the total purchase days and the food needed per day is set to the minimum between the current food needed per day and the remaining units to be purchased.

The loop breaks when the total units can't be purchased within the remaining days, and in this case, the code returns -1. Otherwise, it returns the minimum number of days to be purchased.