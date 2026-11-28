Here is a simple JavaScript solution that handles the problem.

function largestAndSmallest(N) {
    let Nstr = N.toString();
    let maxDigit = '0';
    let minDigit = '9';

    for(let i = 0; i < Nstr.length; i++) {
        if(Nstr[i] > maxDigit) {
            maxDigit = Nstr[i];
        }
        if(Nstr[i] < minDigit) {
            minDigit = Nstr[i];
        }
    }

    return [maxDigit, minDigit];
}

console.log(largestAndSmallest(1234567890));

In this function, we first convert the given number to a string. Then, we initialize the max and min digits as '0' and '9' respectively. We iterate over the string representing the number. If the current digit is larger than the current max digit, we update the max digit. If it's smaller than the current min digit, we update the min digit. After going through all the digits, we return an array with the largest and smallest digits.

Please note that this function only works for positive numbers, and the maximum possible number is 10^18 (18 digits long). The minimum possible digit is '0'. If you want to handle negative numbers, you would need to consider their absolute values and whether they have a digit or not.