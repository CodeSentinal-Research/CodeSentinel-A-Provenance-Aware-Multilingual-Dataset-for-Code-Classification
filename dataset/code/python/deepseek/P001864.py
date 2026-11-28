Sure, I can provide the Python code for finding the maximum search cost in a binary search tree.

def find_max_search_cost():
    n = int(input())

    max_search_cost = 0

    for _ in range(n):
        node_data = input().split()
        max_search_cost += int(node_data[0])

    return max_search_cost

def main():
    max_search_cost = find_max_search_cost()
    print(max_search_cost)

if __name__ == "__main__":
    main()

In this code, the function `find_max_search_cost` takes care of finding the maximum search cost for each node in the BST. The input for each node is the cost to reach this node from the root, which is processed in a loop. 

In the main function, this function is called and the result is printed. 

This code assumes that the input is a valid Binary Search Tree, i.e., each node has exactly two children, and the cost to reach each node is a positive integer.