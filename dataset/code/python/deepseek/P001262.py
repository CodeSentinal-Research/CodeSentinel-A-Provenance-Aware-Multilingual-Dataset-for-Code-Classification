Here is the Python code for the problem:

import heapq

def maxCourses(N, courses):
    courses.sort(key=lambda x: x[1], reverse=True)
    
    max_heap = []
    
    for course in courses:
        if max_heap and max_heap[0] < course[0]:
            heapq.heappushpop(max_heap, course[0])
        else:
            heapq.heappush(max_heap, course[0])
    
    return len(max_heap)

def main():
    N = int(input().strip())
    courses = []
    for i in range(N):
        line = input().strip().split()
        courses.append((int(line[0]), int(line[1])))
    
    print(maxCourses(N, courses))

if __name__ == "__main__":
    main()

This code first reads the number of courses and then the duration and deadline of each course. It then sorts the courses by the deadline in descending order. For each course, it checks if the course with the longest duration can be done in the current time. If it can, it pushes the duration into the heap. If it cannot, it removes the course with the longest duration from the heap. The length of the heap represents the maximum number of courses that can be completed.