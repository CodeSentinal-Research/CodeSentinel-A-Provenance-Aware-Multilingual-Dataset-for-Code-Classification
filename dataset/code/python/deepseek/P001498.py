def min_swaps(binary_string):
    bin_list = list(map(int, binary_string))

    swaps = [0]
    for i in range(len(bin_list) - 1):
        if bin_list[i] == 1 and bin_list[i+1] == 0:
            swaps.append(swaps[-1] + 1)
        else:
            swaps.append(swaps[-1])

    return swaps[-1]

def main():
    binary_string = input()

    print(min_swaps(binary_string))

if __name__ == "__main__":
    main()