Here is the Python code:

def fractional_knapsack():
    N = int(input())
    weights = []
    values = []
    for i in range(N):
        weight, value = map(int, input().split())
        weights.append(weight)
        values.append(value)
    W = int(input())
    items = list(zip(weights, values))
    items.sort(key=lambda x: x[1]/x[0], reverse=True)
    max_value = 0
    fractions = [0]*N
    for i in range(N):
        if items[i][0] <= W:
            fractions[i] = 1
            max_value += items[i][1]
            W -= items[i][0]
        else:
            fractions[i] = W/items[i][0]
            max_value += items[i][1]*fractions[i]
            break
    print("%.2f" % max_value)

if __name__ == "__main__":
    fractional_knapsack()

This code first reads the number of items, weights and values from input, and then calculates the maximum obtainable value. The main part of the code is a loop that iterates over the items in order of their value/weight ratio, starting with the item with the highest ratio. If the item's weight is less than or equal to the remaining weight, it completely fits and is added to the knapsack. Otherwise, it takes up the remaining weight and uses up as much as possible.