def find_trains(records, station):
    return [record for record in records if record['station'] == station]

def main():
    records = [
        {'train': 'Train 1', 'station': 'Station 1'},
        {'train': 'Train 2', 'station': 'Station 2'},
        {'train': 'Train 3', 'station': 'Station 1'},
        {'train': 'Train 4', 'station': 'Station 3'},
    ]

    station = input('Enter station name: ')
    result = find_trains(records, station)

    for record in result:
        print(record['train'])

if __name__ == "__main__":
    main()