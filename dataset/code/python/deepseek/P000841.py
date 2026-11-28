def maxCandies(n, candies, k):
    def maxCandiesPerChild(candies, k):
        return min(candies[i] // 2 for i in range(n))

    def maxCandiesAll(candies):
        return sum(candies)

    maxCandiesPerChild = maxCandiesPerChild(candies, k)

    maxCandies = maxCandiesAll(candies)

    return maxCandiesPerChild

n = 3
candies = [5, 1, 2]
k = 3
print(maxCandies(n, candies, k))