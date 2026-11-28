import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    courses = []
    for _ in range(n):
        duration = int(input_data[idx]); idx += 1
        deadline = int(input_data[idx]); idx += 1
        courses.append((deadline, duration))
        
    courses.sort()
    
    max_heap = []
    time_spent = 0
    
    for deadline, duration in courses:
        if time_spent + duration <= deadline:
            time_spent += duration
            heapq.heappush(max_heap, -duration)
        elif max_heap and -max_heap[0] > duration:
            time_spent += duration + heapq.heappop(max_heap)
            heapq.heappush(max_heap, -duration)
            
    print(len(max_heap))

if __name__ == "__main__":
    solve()

