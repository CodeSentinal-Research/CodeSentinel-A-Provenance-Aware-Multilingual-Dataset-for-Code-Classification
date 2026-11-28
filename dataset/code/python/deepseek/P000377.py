def search_vehicle(records, reg_no):
    for vehicle in records:
        if vehicle['registration_number'] == reg_no:
            return vehicle
    return 'Vehicle Not Found'

def main():
    records = [
        {'registration_number': 'KA1234', 'model': 'Toyota', 'color': 'Red'},
        {'registration_number': 'KA4567', 'model': 'Honda', 'color': 'Black'},
        {'registration_number': 'KA8910', 'model': 'Maruti', 'color': 'White'},
    ]

    reg_no = input('Enter the registration number: ')
    vehicle = search_vehicle(records, reg_no)

    if isinstance(vehicle, str):
        print(vehicle)
    else:
        print('Vehicle Details:', vehicle)

if __name__ == "__main__":
    main()