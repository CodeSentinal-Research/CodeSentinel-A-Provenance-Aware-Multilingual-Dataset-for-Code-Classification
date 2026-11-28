function canConstructRansomNote(ransomNote, magazine) {
    // Create frequency counter object for magazine
    var freq = {};
    for(var i = 0; i < magazine.length; i++) {
        var char = magazine.charAt(i);
        if(freq[char]) {
            freq[char]++;
        } else {
            freq[char] = 1;
        }
    }

    // Decrease frequency of ransomNote characters
    for(var i = 0; i < ransomNote.length; i++) {
        var char = ransomNote.charAt(i);
        if(freq[char] > 0) {
            freq[char]--;
        } else {
            console.log('No');
            return;
        }
    }

    console.log('Yes');
}

This JavaScript function `canConstructRansomNote` takes two strings, `ransomNote` and `magazine`, as input. It first creates a frequency counter object `freq` for `magazine`. It then iterates over `ransomNote` and, for each character, decreases the frequency count in the `freq` object. If at any point, the frequency count for a character in `ransomNote` is less than zero, then the note cannot be constructed from the magazine and we print "No" and return. If no such character is found, then all characters in `ransomNote` can be constructed from `magazine`, and we print "Yes".