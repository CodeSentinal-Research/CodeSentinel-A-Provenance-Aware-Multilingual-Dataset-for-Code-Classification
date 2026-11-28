Sure, I can provide you with a JavaScript solution for this problem. In this solution, I'm assuming that you have a list of bank accounts and the inactivity period. I'm also assuming that you have a function to get the current date and a function to get the last date for inactivity.

Here's the JavaScript code:

function getInactiveAccounts(accounts, inactivityPeriod) {
  const currentDate = new Date();

  // Get the last date for inactivity
  const lastDate = getLastDateForInactivity(accounts, currentDate);

  // Filter accounts based on inactivity period
  const inactiveAccounts = accounts.filter(account => 
    lastDate[account.id] 
    && lastDate[account.id] < currentDate.setMonth(currentDate.getMonth() - inactivityPeriod)
  );

  return inactiveAccounts;
}

// Assuming you have a function getLastDateForInactivity
function getLastDateForInactivity(accounts, currentDate) {
  const lastDate = {};

  for (const account of accounts) {
    lastDate[account.id] = account.lastTransactionDate || currentDate;
  }

  return lastDate;
}

Please note that this is a very simplified solution and you might need to adjust it according to your actual data structure and requirements. Also, you would need to define the structure of your account data and the `getLastDateForInactivity` function. This function could retrieve the last transaction date for each account or it could simply compare the current date to the last transaction date.