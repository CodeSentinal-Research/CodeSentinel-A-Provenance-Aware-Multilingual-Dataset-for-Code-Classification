import {
    Title,
    Overview,
    Heading,
    P,
    Ul,
    Hsep,
    Gap,
    Subheading,
    Code,
    SmallCode,
    Navigation
} from "../Elements";

const GridDP = () => {
    return (
        <>
            <Title>Grid DP</Title>
            <Overview>
                Many Dynamic Programming (DP) problems are naturally set on a 2D grid. The task is often to find a path from a starting point to an ending point, counting the number of ways, or finding the path with the minimum cost or maximum value. Grid DP problems leverage the idea that the solution for a cell often depends on the solutions of its neighboring cells, typically those from which it can be reached.
            </Overview>
            <Hsep />
            <Heading>Example: Unique Paths</Heading>
            <P>
                Let's start with a classic grid DP problem: "Unique Paths".
            </P>
            <P>
                Imagine a robot positioned at the top-left corner of an <SmallCode>m x n</SmallCode> grid. The robot wants to reach the bottom-right corner. The catch? The robot can only move either <strong>down</strong> or <strong>right</strong> at any point in time. The problem asks us to find the number of unique paths the robot can take to reach its destination.
            </P>

            <Subheading>Analyzing the Problem</Subheading>
            <P>
                Consider a cell <SmallCode>(i, j)</SmallCode> in the grid. To reach this cell, the robot must have come either from the cell directly above it, <SmallCode>(i-1, j)</SmallCode> (by moving down), or from the cell directly to its left, <SmallCode>(i, j-1)</SmallCode> (by moving right).
            </P>
            <P>
                This observation forms the core of our dynamic programming approach. The number of ways to reach <SmallCode>(i, j)</SmallCode> is simply the sum of the number of ways to reach <SmallCode>(i-1, j)</SmallCode> and the number of ways to reach <SmallCode>(i, j-1)</SmallCode>.
            </P>
            <P>
                What about the base cases?
            </P>
            <Ul>
                <li>The starting cell <SmallCode>(0, 0)</SmallCode> has exactly one way to be reached (by starting there).</li>
                <li>For any cell in the first row (<SmallCode>(0, j)</SmallCode>), the only way to reach it is by moving right repeatedly from <SmallCode>(0, 0)</SmallCode>. So, there's only 1 way to reach any cell in the first row.</li>
                <li>Similarly, for any cell in the first column (<SmallCode>(i, 0)</SmallCode>), the only way to reach it is by moving down repeatedly from <SmallCode>(0, 0)</SmallCode>. So, there's only 1 way to reach any cell in the first column.</li>
            </Ul>

            <Subheading>The DP Recurrence for Unique Paths</Subheading>
            <P>
                Let <SmallCode>dp[i][j]</SmallCode> represent the number of unique paths to reach cell <SmallCode>(i, j)</SmallCode>.
            </P>
            <Ul>
                <li><strong>Base Case:</strong> <SmallCode>dp[0][0] = 1</SmallCode></li>
                <li><strong>First Row:</strong> <SmallCode>dp[0][j] = 1</SmallCode> for all <SmallCode>j {">"} 0</SmallCode></li>
                <li><strong>First Column:</strong> <SmallCode>dp[i][0] = 1</SmallCode> for all <SmallCode>i {"> "}0</SmallCode></li>
                <li><strong>General Case:</strong> <SmallCode>dp[i][j] = dp[i-1][j] + dp[i][j-1]</SmallCode> for <SmallCode>i {">"} 0</SmallCode> and <SmallCode>j {">"} 0</SmallCode></li>
            </Ul>
            <P>
                The final answer will be <SmallCode>dp[m-1][n-1]</SmallCode>.
            </P>
            <Code
                cpp={`#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        // Initialize first row and first column
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::cout << "Unique paths for 3x7 grid: " << sol.uniquePaths(3, 7) << std::endl; // Output: 28
    std::cout << "Unique paths for 2x2 grid: " << sol.uniquePaths(2, 2) << std::endl; // Output: 2
    return 0;
}`}
                c={`#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    int **dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i) {
        dp[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize first row and first column
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    // Fill the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    int result = dp[m-1][n-1];

    // Free memory
    for (int i = 0; i < m; ++i) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    printf("Unique paths for 3x7 grid: %d\\n", uniquePaths(3, 7)); // Output: 28
    printf("Unique paths for 2x2 grid: %d\\n", uniquePaths(2, 2)); // Output: 2
    return 0;
}`}
                java={`class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        // Initialize first row and first column
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println("Unique paths for 3x7 grid: " + sol.uniquePaths(3, 7)); // Output: 28
        System.out.println("Unique paths for 2x2 grid: " + sol.uniquePaths(2, 2)); // Output: 2
    }
}`}
                python={`class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]

        # Initialize first row and first column
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1

        # Fill the DP table
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]

# Example Usage:
sol = Solution()
print(f"Unique paths for 3x7 grid: {sol.uniquePaths(3, 7)}") # Output: 28
print(f"Unique paths for 2x2 grid: {sol.uniquePaths(2, 2)}") # Output: 2
`}
            />

            <Hsep />
            <Heading>Variation: Unique Paths with Obstacles</Heading>
            <P>
                A common and practical variation of the Unique Paths problem introduces obstacles. In this version, some cells in the grid might be blocked, meaning the robot cannot step on them. We need to find the number of unique paths from the top-left to the bottom-right, avoiding these obstacles.
            </P>
            <P>
                The grid is typically represented by a 2D array where <SmallCode>0</SmallCode> denotes an empty space and <SmallCode>1</SmallCode> denotes an obstacle.
            </P>

            <Subheading>Adapting the DP Logic</Subheading>
            <P>
                The core DP recurrence still holds, but we need to incorporate the obstacle condition.
            </P>
            <Ul>
                <li>If the starting cell <SmallCode>(0, 0)</SmallCode> itself is an obstacle, then there are no paths to the destination, so we return 0.</li>
                <li>For any cell <SmallCode>(i, j)</SmallCode>:
                    <Ul>
                        <li>If <SmallCode>grid[i][j]</SmallCode> contains an obstacle (i.e., <SmallCode>grid[i][j] == 1</SmallCode>), then the number of ways to reach this cell, <SmallCode>dp[i][j]</SmallCode>, is <SmallCode>0</SmallCode>. The robot cannot pass through it.</li>
                        <li>Otherwise, if <SmallCode>grid[i][j]</SmallCode> is an empty space, then <SmallCode>dp[i][j] = dp[i-1][j] + dp[i][j-1]</SmallCode>.</li>
                    </Ul>
                </li>
            </Ul>
            <P>
                The initialization of the first row and column also needs careful handling. If an obstacle is encountered in the first row or column, all subsequent cells in that row/column from that point onwards cannot be reached from the starting point directly, so their path counts also become 0.
            </P>
            <Code
                cpp={`#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start cell has an obstacle, there are no paths
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        // Initialize start cell
        dp[0][0] = 1;

        // Initialize first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) { // Reachable from above and no obstacle
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0; // Obstacle or path blocked above
            }
        }

        // Initialize first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) { // Reachable from left and no obstacle
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0; // Obstacle or path blocked to the left
            }
        }

        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // Current cell is an obstacle
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid1 = {{0,0,0},{0,1,0},{0,0,0}};
    std::cout << "Unique paths with obstacles for grid1: " << sol.uniquePathsWithObstacles(grid1) << std::endl; // Output: 2

    std::vector<std::vector<int>> grid2 = {{0,1},{0,0}};
    std::cout << "Unique paths with obstacles for grid2: " << sol.uniquePathsWithObstacles(grid2) << std::endl; // Output: 1

    std::vector<std::vector<int>> grid3 = {{1,0}};
    std::cout << "Unique paths with obstacles for grid3: " << sol.uniquePathsWithObstacles(grid3) << std::endl; // Output: 0
    return 0;
}`}
                c={`#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    // If the start cell has an obstacle, there are no paths
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    long long **dp = (long long **)malloc(m * sizeof(long long *));
    for (int i = 0; i < m; ++i) {
        dp[i] = (long long *)malloc(n * sizeof(long long));
    }

    // Initialize start cell
    dp[0][0] = 1;

    // Initialize first column
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }

    // Initialize first row
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }

    // Fill the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    long long result = dp[m-1][n-1];

    // Free memory
    for (int i = 0; i < m; ++i) {
        free(dp[i]);
    }
    free(dp);

    return (int)result;
}

int main() {
    // Example 1: {{0,0,0},{0,1,0},{0,0,0}}
    int m1 = 3, n1 = 3;
    int** grid1 = (int**)malloc(m1 * sizeof(int*));
    int colSize1[3] = {3,3,3};
    grid1[0] = (int*)malloc(n1 * sizeof(int)); grid1[0][0]=0; grid1[0][1]=0; grid1[0][2]=0;
    grid1[1] = (int*)malloc(n1 * sizeof(int)); grid1[1][0]=0; grid1[1][1]=1; grid1[1][2]=0;
    grid1[2] = (int*)malloc(n1 * sizeof(int)); grid1[2][0]=0; grid1[2][1]=0; grid1[2][2]=0;
    printf("Unique paths with obstacles for grid1: %d\\n", uniquePathsWithObstacles(grid1, m1, colSize1)); // Output: 2
    for(int i=0; i<m1; ++i) free(grid1[i]); free(grid1);

    // Example 2: {{0,1},{0,0}}
    int m2 = 2, n2 = 2;
    int** grid2 = (int**)malloc(m2 * sizeof(int*));
    int colSize2[2] = {2,2};
    grid2[0] = (int*)malloc(n2 * sizeof(int)); grid2[0][0]=0; grid2[0][1]=1;
    grid2[1] = (int*)malloc(n2 * sizeof(int)); grid2[1][0]=0; grid2[1][1]=0;
    printf("Unique paths with obstacles for grid2: %d\\n", uniquePathsWithObstacles(grid2, m2, colSize2)); // Output: 1
    for(int i=0; i<m2; ++i) free(grid2[i]); free(grid2);
    
    // Example 3: {{1,0}}
    int m3 = 1, n3 = 2;
    int** grid3 = (int**)malloc(m3 * sizeof(int*));
    int colSize3[1] = {2};
    grid3[0] = (int*)malloc(n3 * sizeof(int)); grid3[0][0]=1; grid3[0][1]=0;
    printf("Unique paths with obstacles for grid3: %d\\n", uniquePathsWithObstacles(grid3, m3, colSize3)); // Output: 0
    for(int i=0; i<m3; ++i) free(grid3[i]); free(grid3);

    return 0;
}`}
                java={`class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        // If the start cell has an obstacle, there are no paths
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Use long for dp table to avoid overflow if path count gets very large, though int is usually sufficient for typical constraints.
        // For this problem, max paths typically fit in int, but good practice.
        int[][] dp = new int[m][n];

        // Initialize start cell
        dp[0][0] = 1;

        // Initialize first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
            }
        }

        // Initialize first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0;
            }
        }

        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] grid1 = {{0,0,0},{0,1,0},{0,0,0}};
        System.out.println("Unique paths with obstacles for grid1: " + sol.uniquePathsWithObstacles(grid1)); // Output: 2

        int[][] grid2 = {{0,1},{0,0}};
        System.out.println("Unique paths with obstacles for grid2: " + sol.uniquePathsWithObstacles(grid2)); // Output: 1

        int[][] grid3 = {{1,0}};
        System.out.println("Unique paths with obstacles for grid3: " + sol.uniquePathsWithObstacles(grid3)); // Output: 0
    }
}`}
                python={`class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list[list[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        # If the start cell has an obstacle, there are no paths
        if obstacleGrid[0][0] == 1:
            return 0

        dp = [[0] * n for _ in range(m)]

        # Initialize start cell
        dp[0][0] = 1

        # Initialize first column
        for i in range(1, m):
            # Only set to 1 if the current cell is not an obstacle AND the cell above is reachable
            if obstacleGrid[i][0] == 0 and dp[i-1][0] == 1:
                dp[i][0] = 1
            else:
                dp[i][0] = 0 # Obstacle or path blocked above

        # Initialize first row
        for j in range(1, n):
            # Only set to 1 if the current cell is not an obstacle AND the cell to the left is reachable
            if obstacleGrid[0][j] == 0 and dp[0][j-1] == 1:
                dp[0][j] = 1
            else:
                dp[0][j] = 0 # Obstacle or path blocked to the left

        # Fill the DP table
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0  # Current cell is an obstacle
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]

# Example Usage:
sol = Solution()
grid1 = [[0,0,0],[0,1,0],[0,0,0]]
print(f"Unique paths with obstacles for grid1: {sol.uniquePathsWithObstacles(grid1)}") # Output: 2

grid2 = [[0,1],[0,0]]
print(f"Unique paths with obstacles for grid2: {sol.uniquePathsWithObstacles(grid2)}") # Output: 1

grid3 = [[1,0]]
print(f"Unique paths with obstacles for grid3: {sol.uniquePathsWithObstacles(grid3)}") # Output: 0
`}
            />
            <Gap />
            <P>
                Grid DP problems are a fundamental category in dynamic programming. The "Unique Paths" problem and its variations serve as excellent starting points to understand how to apply DP effectively on 2D structures. Many other problems, like minimum path sum, maximal square, or dungeon game, follow similar patterns but with different recurrence relations based on their specific objectives.
            </P>
            <Navigation chapter={13} id={"grid-dp"}></Navigation>
        </>
    );
};

export default GridDP;
