Here is the JavaScript code that solves the problem:

function exclusive_time(n, m, logs) {
    var res = new Array(n).fill(0);
    var currTime = 0;
    var prevFuncId = -1;

    for(let i = 0; i < m; i++) {
        let log = logs[i].split(':');
        let funcId = parseInt(log[0]);
        let isStart = log[1] === 'start';
        let timestamp = parseInt(log[2]);

        if(prevFuncId !== -1) {
            res[funcId] += currTime - prevTime;
        }

        prevTime = timestamp;
        currTime = timestamp + 1;

        if(isStart && prevFuncId !== funcId) {
            res[prevFuncId] += currTime - prevTime;
        }

        prevFuncId = funcId;
    }

    res[prevFuncId] += currTime - prevTime;

    return res;
}

This code uses a stack to handle the function calls. The time complexity is O(m), where m is the number of logs. The space complexity is O(n), where n is the number of functions.

Please note that this code assumes that the input is valid, i.e., the log strings are well-formed and there are no errors in the input.