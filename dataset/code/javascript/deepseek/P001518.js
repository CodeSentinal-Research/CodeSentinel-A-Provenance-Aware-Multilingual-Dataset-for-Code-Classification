Here is the JavaScript code for the problem:

// Read input
const [N, M, Success] = process.argv.slice(2).map(Number)
const Spells = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n').slice(1).map(Number)
const Potions = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n').slice(1).map(Number)

// Map potions to frequency
const potionsMap = Potions.reduce((acc, potion) => {
  acc[potion] = (acc[potion] || 0) + 1
  return acc
}, {})

// Initialize counter
let count = 0

// Loop through spells
for (let spell of Spells) {
  // Check if the spell can be a successful pair with a potion
  if (potionsMap[spell] >= Success) {
    count += potionsMap[spell]
  }
}

// Print the count
console.log(count)

This script first reads the number of spells and potions, and the success threshold from standard input. It then reads the values of the spells and potions from standard input. The script then counts the number of potions that can be used to form a successful pair with each spell.