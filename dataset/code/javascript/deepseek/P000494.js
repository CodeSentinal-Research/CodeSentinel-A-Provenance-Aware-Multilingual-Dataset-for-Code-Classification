Here is the JavaScript solution:

function dailyTemperatures(temperatures) {
    let result = Array(temperatures.length).fill(0);
    let stack = [];

    for (let i = 0; i < temperatures.length; i++) {
        while (stack.length && temperatures[i] > temperatures[stack[stack.length - 1]]) {
            let j = stack.pop();
            result[j] = i - j;
        }
        stack.push(i);
    }

    return result;
}

This solution uses a stack to keep track of the indices of the temperatures that are currently warmer than the current one. For each temperature, it checks all the warmer temperatures that are currently in the stack and updates the result array accordingly. If there is no warmer temperature for the current one, it pushes the index into the stack.