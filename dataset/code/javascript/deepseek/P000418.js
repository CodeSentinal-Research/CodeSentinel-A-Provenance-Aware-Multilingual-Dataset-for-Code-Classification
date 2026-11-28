function searchEmployees(records, date) {
    const [month, day, year] = date.split('/').map(num => parseInt(num));
    const givenDate = new Date(year, month - 1, day);

    return records.filter(record => {
        const [joinMonth, joinDay, joinYear] = record.joinDate.split('/').map(num => parseInt(num));
        const joinDate = new Date(joinYear, joinMonth - 1, joinDay);
        return joinDate < givenDate;
    });
}

This JavaScript function `searchEmployees` takes an array of records and a date as input. It splits the given date into its components (day, month, year), then constructs a `Date` object for each join date. Finally, it filters the records based on whether the join date is earlier than the given date.

The function returns a new array containing only the records whose join dates are earlier than the given date.