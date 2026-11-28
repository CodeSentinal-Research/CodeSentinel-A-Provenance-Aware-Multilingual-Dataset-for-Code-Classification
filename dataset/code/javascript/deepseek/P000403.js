Here is a simple solution using JavaScript:

function searchTrains(trainRecords, stationName) {
    let result = [];
    for (let train of trainRecords) {
        if (train.station === stationName) {
            result.push(train);
        }
    }
    return result;
}
This function iterates through each train in the given array of train records, and checks if the station name matches the station name provided as an input. If it does, the train record is added to the result array. Finally, the result array is returned.

Please note that this code assumes that the train records are objects with a property 'station' representing the station name from which the train departed. If your train records format is different, you may need to modify the code accordingly.