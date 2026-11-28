function searchPassport(records, passportNumber) {
    for(let i = 0; i < records.length; i++) {
        if(records[i].passportNumber === passportNumber) {
            return records[i];
        }
    }
    return "Passport Not Found";
}