Here is a Python solution for the problem:

def triangle_min_path_sum():
    N = int(input().strip())
    triangle = [[int(x) for x in input().strip().split()] for y in range(N)]
    
    for row in range(N-2, -1, -1):
        for col in range(len(triangle[row]) - 1):
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1])
    
    print(triangle[0][0])

if __name__ == "__main__":
    triangle_min_path_sum()

In this code, we first read the number of rows N. Then we read the triangle rows one by one and store them in a 2D list. We use the triangle property that the minimum path sum to reach a node in a triangle is the minimum path sum to reach the two children plus the current node.

The `min` function is used to find the minimum of two numbers.

The main function call at the end of the code will execute the code when the script is run directly.