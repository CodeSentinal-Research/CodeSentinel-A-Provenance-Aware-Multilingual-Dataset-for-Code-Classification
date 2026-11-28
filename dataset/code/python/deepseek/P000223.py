def activity_selection(start_times, end_times):
    sorted_activities = sorted(range(len(start_times)), key=lambda i: end_times[i])
    
    max_activities = 1
    current_activity = sorted_activities[0]
    
    for activity in sorted_activities[1:]:
        if start_times[activity] >= end_times[current_activity]:
            max_activities += 1
            current_activity = activity
    
    return max_activities

def main():
    N = int(input())
    start_times = []
    end_times = []
    
    for _ in range(N):
        start, end = map(int, input().split())
        start_times.append(start)
        end_times.append(end)
    
    print(activity_selection(start_times, end_times))

if __name__ == "__main__":
    main()