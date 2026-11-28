def maxMeetings(n, start, end):
    intervals = sorted(zip(start, end), key=lambda x: x[1])
    
    max_meetings = 1
    
    current_end = intervals[0][1]
    
    for start, end in intervals[1:]:
        if start > current_end:
            max_meetings += 1
            current_end = end
    
    return max_meetings

n = int(input())
start = [int(input()) for _ in range(n)]
end = [int(input()) for _ in range(n)]

print(maxMeetings(n, start, end))