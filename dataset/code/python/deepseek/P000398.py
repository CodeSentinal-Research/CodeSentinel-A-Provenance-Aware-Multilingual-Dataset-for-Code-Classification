Here's the Python code:

def search_vehicles(records, manufacturer):
    return [record for record in records if record['manufacturer'] == manufacturer]

def main():
    records = [
        {'model': 'A', 'manufacturer': 'A'},
        {'model': 'B', 'manufacturer': 'B'},
        {'model': 'C', 'manufacturer': 'A'},
        {'model': 'D', 'manufacturer': 'B'}
    ]
    manufacturer = 'A'
    results = search_vehicles(records, manufacturer)
    print(results)

if __name__ == "__main__":
    main()

This code defines a function `search_vehicles` which takes a list of vehicle records and a manufacturer name, and returns a list of vehicle records that match the specified manufacturer. 

In the `main` function, we define some vehicle records and a manufacturer name, and then call the `search_vehicles` function with these values. The results are printed out.