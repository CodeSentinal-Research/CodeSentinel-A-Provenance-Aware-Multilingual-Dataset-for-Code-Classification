def isValidSerialization(preorder):
    nodes = preorder.split(',')
    diff = 1
    for node in nodes:
        if node == '#':
            diff -= 1
        else:
            diff += 1
        if diff < 0:
            return False
    return diff == 0

def main():
    serialization = input('Enter the serialization: ')
    print(isValidSerialization(serialization))

if __name__ == "__main__":
    main()