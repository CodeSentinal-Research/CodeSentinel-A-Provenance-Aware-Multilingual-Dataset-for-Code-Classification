# problem title : Print Alphabet from Z to A
# Print the uppercase alphabet in reverse order.
print(*map(chr, range(ord('Z'), ord('A') - 1, -1)))
