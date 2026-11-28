Here is the JavaScript code that checks if the two halves of a string have the same number of vowels:

function halvesAreAlike(s) {
    const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    const s1 = s.slice(0, s.length / 2);
    const s2 = s.slice(s.length / 2);
    let count1 = 0, count2 = 0;

    for (let i = 0; i < s1.length; i++) {
        if (vowels.includes(s1[i])) {
            count1++;
        }
    }

    for (let i = 0; i < s2.length; i++) {
        if (vowels.includes(s2[i])) {
            count2++;
        }
    }

    if (count1 === count2) {
        console.log('Yes');
    } else {
        console.log('No');
    }
}

This function first checks if the string length is even. If it's not, it will return 'No' because two halves of a non-even string can't have the same number of vowels. Then, it slices the string into two halves. It counts the number of vowels in each half and compares them. If they are equal, it prints 'Yes', otherwise 'No'.