Here is the Python code for generating all unique Binary Search Trees. 

from collections import defaultdict

def generateTrees(self, n: int):
    class Solution:
        def generateTrees(self, n: int) -> List['TreeNode']:
            def generate(lo, hi):
                if lo > hi:
                    return [None]
                all_trees = []
                for i in range(lo, hi + 1):
                    for left in generate(lo, i - 1):
                        for right in generate(i + 1, hi):
                            root = TreeNode(i)
                            root.left = left
                            root.right = right
                            all_trees.append(root)
                return all_trees

            return generate(1, n) if n else []

    return Solution().generateTrees(n)
This Python program will output all possible unique Binary Search Trees for a given integer N. The function 'generateTrees' is a part of the main function that takes an integer N as input and returns a list of all unique BSTs for the given integer N. The function 'generate' is a helper function that generates all unique BSTs for a given range of numbers lo and hi.

Please note that the above code is not a complete program as it does not include any main function and input handling. 

To use this code, you should create a new Python file and copy the code into it. Then, in the main function of the file, you can call the function like this:

def main():
    N = int(input("Enter the value of N: "))
    result = generateTrees(N)
    print("All unique BSTs for", N, "are:")
    for tree in result:
        print(tree)
    print("Total count:", len(result))

if __name__ == "__main__":
    main()
In this main function, it takes an input N and prints all unique BSTs for the given integer N, then prints the total count.