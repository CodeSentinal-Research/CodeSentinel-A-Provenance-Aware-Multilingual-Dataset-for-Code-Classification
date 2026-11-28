// JavaScript solution for reversing a string

function reverseString(s) {
    let strArr = s.split("");
    let start = 0;
    let end = strArr.length - 1;

    while (start < end) {
        let temp = strArr[start];
        strArr[start] = strArr[end];
        strArr[end] = temp;

        start++;
        end--;
    }

    return strArr.join("");
}

console.log(reverseString("Hello World"));