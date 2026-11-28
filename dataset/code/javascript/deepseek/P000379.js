Here is a simple JavaScript solution using an array of objects to store the train data:

let trainData = [
  {
    trainNumber: "123",
    trainName: "Train 1",
    destination: "New York",
    departure: "San Francisco",
    availableSeats: 50,
  },
  {
    trainNumber: "456",
    trainName: "Train 2",
    destination: "San Francisco",
    departure: "Los Angeles",
    availableSeats: 30,
  },
  // more train data...
];

function searchTrain(trainNumber) {
  for (let i = 0; i < trainData.length; i++) {
    if (trainData[i].trainNumber === trainNumber) {
      return trainData[i];
    }
  }
  return "Train Not Found";
}

// Usage
console.log(searchTrain("456")); // should return { trainNumber: '456', trainName: 'Train 2', destination: 'San Francisco', departure: 'Los Angeles', availableSeats: 30 }
console.log(searchTrain("1234")); // should return "Train Not Found"

This code defines a function `searchTrain` that takes a train number as a parameter. It then loops through the `trainData` array, comparing each train's train number to the input train number. If it finds a match, it returns the corresponding train object. If it doesn't find a match, it returns the string "Train Not Found".

Note: This is a very basic example and doesn't include any form of input handling, validation, error checking, or efficiency improvements. For a real-world application, you'd likely want to use a database or a more complex data structure to store and search this data.