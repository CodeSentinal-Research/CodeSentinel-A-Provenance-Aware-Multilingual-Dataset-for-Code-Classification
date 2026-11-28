# problem title : Calculate Electricity Bill
# The statement does not specify the slab rates, so the rate table must be supplied by the dataset owner.
# This implementation uses a simple progressive example: first 100 units at 1, next 100 at 2, remaining at 3.
units = int(input())
first = min(units, 100)
second = min(max(units - 100, 0), 100)
third = max(units - 200, 0)
print(first + 2 * second + 3 * third)
