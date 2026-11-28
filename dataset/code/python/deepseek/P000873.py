def decode(encoded, first):
    result = [first]
    for i in range(len(encoded)):
        result.append(result[-1] ^ encoded[i])
    return result