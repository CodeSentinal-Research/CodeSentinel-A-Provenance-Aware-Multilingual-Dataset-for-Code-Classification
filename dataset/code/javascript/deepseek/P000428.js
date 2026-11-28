function findEvents(events, date) {
    let result = [];
    for(let event of events) {
        if(new Date(event.date).toDateString() === new Date(date).toDateString()) {
            result.push(event);
        }
    }
    return result;
}
This function takes an array of event records and a date as inputs, then iterates through each event. If the event's date is the same as the given date, the event is added to the result array. The result array is then returned.