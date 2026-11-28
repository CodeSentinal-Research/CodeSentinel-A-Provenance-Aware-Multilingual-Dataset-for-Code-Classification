def search_hotel_by_id(hotels, hotel_id):
    for hotel in hotels:
        if hotel['id'] == hotel_id:
            return hotel
    return None

def main():
    hotels = [
        {'id': 1, 'name': 'Hotel A', 'location': 'Location A'},
        {'id': 2, 'name': 'Hotel B', 'location': 'Location B'},
        {'id': 3, 'name': 'Hotel C', 'location': 'Location C'},
    ]

    hotel_id = 2

    hotel = search_hotel_by_id(hotels, hotel_id)

    if hotel:
        print(f"Hotel Details: {hotel}")
    else:
        print("Hotel Not Found")

if __name__ == "__main__":
    main()