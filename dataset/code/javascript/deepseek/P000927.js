Here is a simple JavaScript solution for the problem:

function convertBase(number, baseA, baseB) {
    if (baseA < 2 || baseA > 36 || baseB < 2 || baseB > 36 || !Number.isInteger(baseA) || !Number.isInteger(baseB)) {
        throw new Error('Invalid input. Bases should be integers between 2 and 36, and numbers should be integers.');
    }

    let result = '';
    let alphabet = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';

    if (baseA === 10) {
        result = number.toString();
    } else {
        let absNumber = Math.abs(number);
        while (absNumber) {
            let remainder = absNumber % baseB;
            absNumber = Math.floor(absNumber / baseB);
            result = (alphabet[remainder] || '0') + result;
        }
        if (number < 0 && baseA !== 10) {
            result = '-' + result;
        }
    }

    return result;
}

This function first checks if the input is valid (i.e., baseA and baseB are integers between 2 and 36). It then converts the number into baseA using a while loop. For each iteration, it calculates the remainder of the division by baseB and adds the corresponding character from the alphabet to the result string. If the number is negative and baseA is not 10, it adds a '-' sign to the result.