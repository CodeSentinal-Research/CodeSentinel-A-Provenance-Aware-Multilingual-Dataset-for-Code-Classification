function convertDays(days) {
  if (days < 1 || days > 100000) {
    throw new Error('Invalid input. Please enter a positive integer between 1 and 100000.');
  }

  const oneYearInDays = 365;
  const oneWeekInDays = 7;

  const years = Math.floor(days / oneYearInDays);
  const weeks = Math.floor((days % oneYearInDays) / oneWeekInDays);
  const remainingDays = days % oneYearInDays % oneWeekInDays;

  return { years, weeks, remainingDays };
}