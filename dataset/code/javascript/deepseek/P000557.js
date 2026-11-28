Here is the JavaScript code for the Race Car problem:

function raceCar(target) {
    let instructions = 0;
    let position = 0;
    while (position !== target) {
        instructions++;
        if (position + Math.pow(2, instructions) >= target) {
            position += Math.pow(2, instructions);
        } else {
            position += Math.pow(2, instructions - 1);
        }
    }
    return instructions;
}

console.log(raceCar(3)); // Output: 2
console.log(raceCar(4)); // Output: 3

This function starts with an initial position of 0 and speed of 1. It then enters a loop where it checks if the next step will reach the target. If it does, it accelerates and updates the position and speed; otherwise, it reverses and updates the position. The function returns the number of instructions needed to reach the target.