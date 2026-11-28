Sure, here is the Python code for your problem:

def count_unique_paths(m, n):
    paths = [[0 for _ in range(n+1)] for _ in range(m+1)]
    
    for i in range(m+1):
        paths[i][0] = 1
        
    for j in range(n+1):
        paths[0][j] = 1
        
    for i in range(1, m+1):
        for j in range(1, n+1):
            paths[i][j] = paths[i-1][j] + paths[i][j-1]
            
    return paths[m][n]

def main():
    m = int(input("Enter the value of m: "))
    n = int(input("Enter the value of n: "))
    print("The number of unique paths is: ", count_unique_paths(m, n))

if __name__ == "__main__":
    main()
This code first creates a 2D list to store the count of unique paths. It then fills in the first row and first column to 1. For all other positions, it calculates the count of unique paths as the sum of unique paths from the top and left.