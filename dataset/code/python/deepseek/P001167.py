Here is the Python code to solve the problem:

def paint_house(N, costs):
    min1 = costs[0][0]
    min2 = costs[0][1]
    min3 = costs[0][2]

    min1_new = min2
    min2_new = min3
    min3_new = float('inf')

    for i in range(1, N):
        min1, min2, min3 = min2, min3, min1_new + min2_new + min3_new

        min1_new, min2_new, min3_new = min1, min2, min1 + min2 + min3

    return min1

N = int(input().strip())
costs = [[int(cost) for cost in input().strip().split(' ')] for _ in range(N)]

print(paint_house(N, costs))

This code first initializes the minimum cost for painting the first house and the minimum cost for the second house. It then iterates over the costs and updates the minimum cost for painting the current house and the previous house. Finally, it returns the minimum cost for painting the last house.

The input handling part of the code reads the number of houses and the costs for painting the houses. It then prints the minimum total cost.