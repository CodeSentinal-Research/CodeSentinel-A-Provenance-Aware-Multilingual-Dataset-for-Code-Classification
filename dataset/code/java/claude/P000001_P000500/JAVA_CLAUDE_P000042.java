public class Solution {
    public String checkVowelOrConsonant(char c) {
        if (!Character.isLetter(c)) return "Neither";
        char lower = Character.toLowerCase(c);
        if ("aeiou".indexOf(lower) != -1) return "Vowel";
        return "Consonant";
    }
}
