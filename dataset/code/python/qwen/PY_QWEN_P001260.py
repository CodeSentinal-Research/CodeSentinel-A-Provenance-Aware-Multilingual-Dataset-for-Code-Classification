import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    a = int(input_data[0])
    b = int(input_data[1])
    c = int(input_data[2])
    
    heap = [(-a, 'a'), (-b, 'b'), (-c, 'c')]
    heapq.heapify(heap)
    
    result = []
    
    while heap:
        count1, char1 = heapq.heappop(heap)
        count1 = -count1
        
        if result and result[-1] == char1 and result[-2] == char1:
            if not heap:
                break
            count2, char2 = heapq.heappop(heap)
            count2 = -count2
            result.append(char2)
            count2 -= 1
            if count2 > 0:
                heapq.heappush(heap, (-count2, char2))
            heapq.heappush(heap, (-count1, char1))
        else:
            result.append(char1)
            count1 -= 1
            if count1 > 0:
                heapq.heappush(heap, (-count1, char1))
                
    print("".join(result))

if __name__ == "__main__":
    solve()

