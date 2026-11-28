Sure, here's the JavaScript code to find all active user accounts.

function searchActiveUsers(userAccounts) {
    const activeUsers = userAccounts.filter(user => user.isActive);
    return activeUsers;
}

In this code, `userAccounts` is an array of user objects, each containing a `isActive` property which is a boolean indicating whether the user is active.

The `filter` method is used to create a new array with all elements that pass the test implemented by the provided function. In this case, the test is whether `isActive` is true.

Please note that this function assumes that `userAccounts` is an array of user objects with a `isActive` property. You may need to adjust the code if the structure of your user accounts is different.