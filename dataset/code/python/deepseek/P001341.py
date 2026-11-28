Here is the Python code:

def printTimes(leds):
    if leds < 0 or leds > 10:
        return

    hours = []
    minutes = []

    for i in range(12):
        for j in range(60):
            if (i < 10 and int(i) << 6 | j) < (1 << 6):  
                hours.append((i << 6 | j, i, j))
            if (leds - 2) > 0 and i < 5:  
                minutes.append(((leds - 2) << 6 | j, i, j))

    valid_times = list(set([t for t in hours if t in minutes]))

    valid_times.sort()

    for time in valid_times:
        print('%d:%02d' % (time[1], time[2]))

def main():
    leds = int(input().strip())
    printTimes(leds)

if __name__ == '__main__':
    main()

This code defines a function `printTimes` that prints all valid times in ascending order. It first checks if the number of LEDs turned on is within the valid range. Then, it loops through all possible combinations of hours and minutes. It filters out the valid times by checking whether the time for the hours is less than the time for the minutes. Finally, it sorts the valid times by time and prints out the valid times. The `main` function is the entry point of the program, which reads the number of LEDs turned on and calls `printTimes`.