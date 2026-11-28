Here is the JavaScript code for the provided problem:

function compareVersion(version1, version2) {
    var arr1 = version1.split('.');
    var arr2 = version2.split('.');

    while (arr1.length || arr2.length) {
        var num1 = arr1.length ? parseInt(arr1.shift()) : 0;
        var num2 = arr2.length ? parseInt(arr2.shift()) : 0;

        if (num1 > num2) {
            return 1;
        } else if (num1 < num2) {
            return -1;
        }
    }

    return 0;
}

In the above code, we are breaking both version strings into arrays by '.' character. Then, we are comparing corresponding elements of these arrays. If the elements are not equal (or the end of the shorter array is reached), we return the result of the comparison (1 if first number of the longer array is greater, -1 if the second is, and 0 otherwise). If the end of both arrays is reached, it means that one of the versions is the same up to that point, so we just return 0.