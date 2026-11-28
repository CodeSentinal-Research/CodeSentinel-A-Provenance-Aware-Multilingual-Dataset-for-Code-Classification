Here is the JavaScript code for the problem:

function searchRestaurants(records, minRating) {
    // Filter restaurants with a rating higher or equal to the threshold
    let matchingRestaurants = records.filter(restaurant => restaurant.rating >= minRating);

    // Sort the restaurants in descending order of their ratings
    matchingRestaurants.sort((a, b) => b.rating - a.rating);

    // Return the matching restaurants
    return matchingRestaurants;
}

// Example usage:
let restaurants = [
    { name: 'Restaurant 1', rating: 4.5 },
    { name: 'Restaurant 2', rating: 3 },
    { name: 'Restaurant 3', rating: 5 },
    { name: 'Restaurant 4', rating: 4 },
    { name: 'Restaurant 5', rating: 4.7 }
];

let minRating = 4;

let result = searchRestaurants(restaurants, minRating);

console.log(result);

In this code, the `searchRestaurants` function first filters out the restaurants whose rating is less than the threshold. Then it sorts the remaining restaurants in descending order of their ratings. Finally, it returns the sorted list of restaurants.

The `restaurants` array holds the input data, `minRating` is the threshold rating, and `result` is the result of the `searchRestaurants` function.

You can run this code with different input data to test the functionality.