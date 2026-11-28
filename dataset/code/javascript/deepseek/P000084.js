// JavaScript program to check eligibility for voting

// Function to check eligibility for voting
function checkEligibility(age) {
  if (age >= 0 && age <= 120) {
    if (age >= 18) {
      console.log("Eligible");
    } else {
      console.log("Not Eligible");
    }
  } else {
    console.log("Invalid age. Please enter a non-negative integer age.");
  }
}

// Calling the function with an age
checkEligibility(15); // Replace 15 with any age you want