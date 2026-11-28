function searchVehicles(records, year) {
    // Filter out the records where the year is not greater than the given year
    const filteredRecords = records.filter(record => record.year > year);
    
    // Return the filtered records
    return filteredRecords;
}