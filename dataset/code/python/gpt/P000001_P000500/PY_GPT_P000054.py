# problem title : Print Alphabet from A to Z
# Print the uppercase alphabet in forward order.
print(*[chr(code) for code in range(ord('A'), ord('Z') + 1)])
