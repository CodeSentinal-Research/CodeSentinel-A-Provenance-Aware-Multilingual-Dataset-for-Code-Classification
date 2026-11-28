Here's the Python code for the problem:

def min_boats(N, weights, boat_capacity):
    weights.sort()
    left, right = 0, N - 1
    boats = 0
    while left <= right:
        if weights[left] + weights[right] <= boat_capacity:
            boats += 1
            left += 1
            right -= 1
        else:
            boats += 1
            right -= 1
    if boats > N:
        return -1
    return boats

def main():
    N, M = map(int, input().split())
    weights = list(map(int, input().split()))
    boat_capacity = list(map(int, input().split()))
    print(min_boats(N, weights, boat_capacity))

if __name__ == "__main__":
    main()

In this code, we first sort the weights of the people. Then we use two pointers, `left` and `right`, to traverse the sorted list from both ends. If the sum of the weights at the `left` and `right` indices is smaller than the boat capacity, we can carry both people and move both pointers one step forward. Otherwise, we carry only one person and move the pointer one step forward. This process is repeated until we have covered all people. If after all people we still have boats, we return -1 as it's impossible to rescue all people with given capacities.