import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    strs = input_data[1:n+1]
    encoded = ""
    for s in strs:
        encoded += str(len(s)) + "#" + s
    print(encoded)
    decoded = []
    i = 0
    while i < len(encoded):
        j = encoded.find('#', i)
        length = int(encoded[i:j])
        decoded.append(encoded[j+1:j+1+length])
        i = j + 1 + length
    print(" ".join(decoded))
solve()
