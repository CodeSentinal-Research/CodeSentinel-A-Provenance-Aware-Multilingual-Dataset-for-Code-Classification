Here is the JavaScript code to solve the problem:

function findExpiredMemberships(records, currentDate) {
    return records.filter(record => record.expiryDate <= currentDate);
}

In this code, the `records` parameter is an array of objects, each representing a membership and has an `expiryDate` property (assumed to be a Date object). The `currentDate` parameter is the current date and time.

The `findExpiredMemberships` function uses the `filter` method to create a new array with all memberships whose `expiryDate` is earlier than or equal to the `currentDate`.

The `filter` method iterates over each record in the `records` array and applies a provided function (here, a function that returns true if the `expiryDate` is before or equal to `currentDate`, and false otherwise). This function is passed as an argument to `filter`, and only the records for which this function returns true are included in the new array.

This function returns the new array, which contains all the memberships whose `expiryDate` has passed or is now expired.