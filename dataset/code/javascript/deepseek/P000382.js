Sure, here's the JavaScript code:

function searchEmailByUsername(records, username) {
    for (let i = 0; i < records.length; i++) {
        if (records[i].username === username) {
            return records[i].email;
        }
    }
    return "User Not Found";
}

This function loops through the input records array to find a user with the matching username. If a match is found, it returns the email address. If no match is found, it returns the string "User Not Found". The input records array should be an array of objects, each with a `username` property and an `email` property. The input `username` is a string.

You can call this function with a user records array and a username as follows:

let records = [
    {username: "alice", email: "alice@example.com"},
    {username: "bob", email: "bob@example.com"},
    {username: "charlie", email: "charlie@example.com"}
];
console.log(searchEmailByUsername(records, "alice"));  // Output: alice@example.com
console.log(searchEmailByUsername(records, "dave"));  // Output: User Not Found

Please note that in this example, the email addresses are hard-coded into the function. In a real-world application, you would likely retrieve these from a database or another source.