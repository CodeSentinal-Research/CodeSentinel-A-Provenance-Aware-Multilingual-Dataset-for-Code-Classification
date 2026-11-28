Here is the Python code for the problem:

class Interval:
    def __init__(self, start=0, end=0):
        self.start = start
        self.end = end

class SummaryRanges:
    def __init__(self):
        self.intervals = []

    def addNum(self, value: int) -> None:
        self.intervals.append(Interval(value, value))
        self.intervals.sort(key=lambda x: (x.start, x.end))

    def getIntervals(self) -> list[Interval]:
        result = []
        current = Interval(self.intervals[0].start, self.intervals[0].end)

        for i in range(1, len(self.intervals)):
            if self.intervals[i].start <= current.end + 1:
                current.end = max(current.end, self.intervals[i].end)
            else:
                result.append(current)
                current = Interval(self.intervals[i].start, self.intervals[i].end)

        result.append(current)

        return result

def main():
    sr = SummaryRanges()

    for num in [1, 3, 7, 2, 6, 9, 4, 8, 0]:
        sr.addNum(num)

    for intervals in sr.getIntervals():
        print(intervals.start, intervals.end)

    for intervals in sr.getIntervals():
        print(intervals.start, intervals.end)

if __name__ == "__main__":
    main()

This program first defines an `Interval` class to represent intervals of numbers, then the `SummaryRanges` class. It defines the `addNum` method to add a new number to the list of intervals, and the `getIntervals` method to return all disjoint intervals.

In the `main` function, we create an instance of `SummaryRanges` and add numbers to it, then print all disjoint intervals for each pair of `getIntervals` calls.