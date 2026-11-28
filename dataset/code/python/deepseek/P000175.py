def wave_array(n, arr):
    arr.sort()
    wave = []
    while len(arr) > 0:
        wave.append(arr.pop(0))
        if len(arr) > 0:
            wave.append(arr.pop())
    return wave

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    wave = wave_array(n, arr)
    print(" ".join(map(str, wave)))

if __name__ == '__main__':
    main()

This code first reads the number of elements in the array and then the array itself. It then sorts the array, pops the first element and appends it to the wave array, and then if there are more elements in the array, pops the last element and appends it to the wave array. This continues until there are no more elements in the array. The wave array is then printed out.