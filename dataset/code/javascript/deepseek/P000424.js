Here is a JavaScript solution using an object to store email counts:

function findDuplicateEmails(records) {
    // Create an object to store email counts
    var emailCounts = {};

    // Iterate over all records
    for (var i = 0; i < records.length; i++) {
        // Get the email address
        var email = records[i];

        // If the email address is not in the object, add it with a count of 1
        if (!emailCounts.hasOwnProperty(email)) {
            emailCounts[email] = 1;
        }
        // Otherwise, increment the count
        else {
            emailCounts[email] += 1;
        }
    }

    // Get all keys (email addresses) in the object that have a count more than 1
    var duplicatedEmails = [];
    for (var email in emailCounts) {
        if (emailCounts[email] > 1) {
            duplicatedEmails.push(email);
        }
    }

    return duplicatedEmails;
}

This function takes an array of email records as an input, calculates the frequency of each email address using a JavaScript object, and returns an array of duplicated email addresses.

Please note that this solution assumes that the input is already a valid array of email records and that the emails are unique. It does not handle empty or invalid email records. You might want to add input validation depending on your specific use case.