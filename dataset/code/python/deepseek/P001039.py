Here is a Python solution for the problem:

def furthest_reachable_building(N, heights, bricks, ladders):
    max_height = max(heights)
    sorted_heights = sorted(heights, reverse=True)
    bricks_left = bricks
    ladders_used = 0

    for i in range(N):
        if sorted_heights[i] <= max_height:
            max_height -= sorted_heights[i]
            if bricks_left > 0:
                bricks_left -= 1
            elif ladders_used < ladders:
                ladders_used += 1
            else:
                return i
    return -1

def main():
    N = int(input().strip())
    heights = list(map(int, input().strip().split()))
    bricks, ladders = map(int, input().strip().split())
    print(furthest_reachable_building(N, heights, bricks, ladders))

if __name__ == "__main__":
    main()

In this code, we first define a function `furthest_reachable_building` that takes in the number of buildings `N`, a list of heights `heights`, the number of bricks `bricks`, and the number of ladders `ladders`. The function first calculates the maximum height among the buildings. It then sorts the heights in descending order and iterates over the sorted list. For each building, it checks if the current building's height is less than or equal to the maximum height. If it is, it subtracts the height from the maximum height. It also checks if there are any bricks left and if the number of ladders used is less than the total number of ladders. If the current building's height is less than or equal to the maximum height and there are bricks left or if the number of ladders used is less than the total number of ladders, it returns the index of the current building. If no building can be reached, it returns -1.

The `main` function handles the input and call the `furthest_reachable_building` function.