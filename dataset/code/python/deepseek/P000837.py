Here is the Python code:

def minmaxGasDist(stations, n, k):
    def valid(dist):
        refills, used = k + 1, 0
        for station in stations:
            refills, used = refills - (station - last) // dist, used + (station - last) // dist
            if used > refills:
                return False
            last = station
        return used > refills

    def binary(left, right):
        while right - left > 1e-6:
            mid = (left + right) / 2
            if not valid(mid):
                left = mid
            else:
                right = mid
        return right

    last, refills = 0, k + 1
    return binary(0, max(stations) * 1.0)



In the code above, the valid function checks if it's possible to fill all the gas in a given distance. The binary function uses binary search to find the smallest valid distance. The main function calls the binary function with the given input and the range of possible distances.