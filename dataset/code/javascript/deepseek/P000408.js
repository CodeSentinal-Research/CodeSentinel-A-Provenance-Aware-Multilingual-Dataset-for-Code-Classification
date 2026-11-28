Here is a simple JavaScript solution using the `filter` method to find all email addresses belonging to a given domain:

function searchEmailsByDomain(records, domain) {
    return records.filter(record => record.includes('@' + domain));
}

This function takes an array of email records and a domain name as arguments. It returns a new array that contains only the email addresses that end with the provided domain. The `includes` method is used to check if a record ends with the specified domain.

Please note that this solution assumes that the email records are stored as strings and that they are in the format "user@domain". If your input data is different, you may need to adjust the solution accordingly.