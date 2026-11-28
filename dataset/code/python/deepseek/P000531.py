Here is the Python code for the given problem:

class RecentCounter:

    def __init__(self):
        self.requests = []

    def ping(self, t: int) -> int:
        self.requests.append(t)
        low = max(0, t - 3000)
        high = t
        while self.requests[high] > t:
            high -= 1
        while self.requests[low] < t:
            low += 1
        return high - low + 1

def main():
    rc = RecentCounter()
    requests = [1, 1000, 3001, 3002]
    for t in requests:
        print(rc.ping(t))

if __name__ == "__main__":
    main()

In this code, we use a list to store the timestamps of each request. For each new request, we add its timestamp to the end of the list. Then, we find the two indices that would give us the number of requests in the last 3000 milliseconds. We subtract the low index from the high index to get the number of requests and add 1 to account for the current request. In the main function, we create an instance of the RecentCounter class and use it to process the requests.