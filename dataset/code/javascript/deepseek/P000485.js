Here is a simple JavaScript code using a Stack to solve this problem:

function asteroidCollision(asteroids) {
    let stack = [];
    for (let asteroid of asteroids) {
        while (stack.length && stack[stack.length - 1] > 0 && asteroid < 0 && stack[stack.length - 1] < -asteroid) {
            if (stack[stack.length - 1] < -asteroid) {
                asteroid = 0;
            } else {
                stack[stack.length - 1] = 0;
                break;
           
            }
            stack.pop();
        }
        stack.push(asteroid);
    }
    return stack;
}

This function takes an array of asteroid sizes as input and returns a new array where asteroids that have collided (i.e., sizes of both asteroids are positive and the smaller asteroid explodes) are removed.

The function uses a stack to store asteroid sizes. It iterates over the asteroid sizes in the input array from left to right. If an asteroid is in the stack and is moving to the left (i.e., its size is positive) and an asteroid at the top of the stack is moving to the right (i.e., its size is negative) and both are moving in the same direction, an explosion happens.

If the asteroid at the top of the stack is larger than the current asteroid, the current asteroid explodes and becomes 0. If the asteroid at the top of the stack is smaller than the current asteroid, the current asteroid does not explode and becomes 0. If the asteroids are moving in the same direction, both asteroids do not explode and stay in the stack.

If an asteroid explodes, it is removed from the stack and its size is set to 0.

Finally, the function returns the remaining asteroids in the stack.