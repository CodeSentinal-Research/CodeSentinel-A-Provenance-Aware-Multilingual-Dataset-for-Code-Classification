def search_vehicles(records, year):
    filtered_records = [record for record in records if record['year'] > year]

    return filtered_records

def main():
    n = int(input().strip())
    records = []

    for i in range(n):
        record = {}
        record['year'], record['make'], record['model'], record['type'] = input().strip().split()
        records.append(record)

    year = int(input().strip())

    results = search_vehicles(records, year)

    for record in results:
        print(f"{record['year']} {record['make']} {record['model']} {record['type']}")

main()