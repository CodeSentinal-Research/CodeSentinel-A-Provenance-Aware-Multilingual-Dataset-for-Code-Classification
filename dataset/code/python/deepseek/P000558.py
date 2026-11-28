from typing import List

class Solution:
    def min_moves_to_reach_target(self, n: int, grid: List[List[int]]) -> int:
        directions = {
            0: [(0, 1), (1, 0), (0, -1), (-1, 0)], 
            1: [(0, -1), (1, 0), (0, 1), (-1, 0)], 
        }
        
        start_pos = (0, 0)
        target_pos = (n-1, n-1)
        
        visited = set()
        queue = [(grid[start_pos[0]][start_pos[1]], start_pos, 0)]
        
        while queue:
            cur_val, cur_pos, cur_rotation = queue.pop(0)
            
            if cur_pos == target_pos:
                return cur_rotation
            
            for next_pos in directions[cur_val]:
                next_pos_rotation = cur_rotation
                next_val = grid[next_pos[0]][next_pos[1]]
                
                if next_val == 1:
                    next_pos_rotation += 1
                
                if (next_pos[0] >= 0 and next_pos[0] < n and
                    next_pos[1] >= 0 and next_pos[1] < n and
                    grid[next_pos[0]][next_pos[1]] == 0 and
                    next_pos not in visited):
                    visited.add(next_pos)
                    queue.append((next_val, next_pos, next_pos_rotation))
        
        return -1

def main():
    n = 3
    grid = [[0, 0, 0], [1, 1, 1], [0, 1, 0]]
    sol = Solution()
    print(sol.min_moves_to_reach_target(n, grid))

if __name__ == "__main__":
    main()