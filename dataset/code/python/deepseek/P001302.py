Here is the Python code for the problem:

def minMeetingRooms(meetings):
    start = []
    end = []
    for meeting in meetings:
        start.append(meeting[0])
        end.append(meeting[1])

    start.sort()
    end.sort()

    rooms = i = 0
    j = 0

    while i < len(start) and j < len(end):
        if start[i] < end[j]:
            rooms += 1
            i += 1
        else:
            rooms -= 1
            j += 1

    return rooms

def main():
    N = int(input().strip())
    meetings = []

    for _ in range(N):
        start, end = map(int, input().strip().split())
        meetings.append((start, end))

    print(minMeetingRooms(meetings))

if __name__ == "__main__":
    main()

In this code, we are using a greedy algorithm to solve the problem. The key idea is to use a priority queue to keep track of the ending time of each meeting. This way, when a new meeting starts, we know the earliest ending time (which is the top of the queue), and we can quickly check if a room is available.

The time complexity of this solution is O(N log N) due to the sorting operation, where N is the number of meetings. The space complexity is O(N) for storing the start and end times.