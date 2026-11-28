# problem title : Average of Array Elements
# Average equals the total divided by the number of elements.
n = int(input()); values = list(map(int, input().split()))
print(sum(values[:n]) / n)
