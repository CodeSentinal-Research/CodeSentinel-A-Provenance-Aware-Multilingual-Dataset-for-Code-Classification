Here is a Python solution using list comprehension and the `input` and `print` functions to handle the input and output.

def find_restaurants(records, min_rating):
    return [restaurant for restaurant in records if restaurant['rating'] >= min_rating]

def main():
    num_restaurants = int(input("Enter the number of restaurants: "))
    records = []

    for _ in range(num_restaurants):
        restaurant = input("Enter restaurant details (name, rating): ").split(', ')
        records.append({'name': restaurant[0], 'rating': float(restaurant[1])})

    min_rating = float(input("Enter the minimum rating: "))

    restaurants = find_restaurants(records, min_rating)

    for restaurant in restaurants:
        print(restaurant['name'], restaurant['rating'])

if __name__ == "__main__":
    main()

This program first takes the number of restaurants as input and then the details of each restaurant as input. It then takes the minimum rating as input and uses this to find all restaurants with a rating greater or equal to the minimum rating. The results are then printed out.

This solution assumes that the input will always be valid. If the input might not be valid, you should add error handling code to ensure that the program behaves correctly.