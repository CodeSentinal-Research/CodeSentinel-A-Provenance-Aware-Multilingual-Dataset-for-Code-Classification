public class Solution {
    public String checkCase(char c) {
        if (Character.isUpperCase(c)) return "Uppercase";
        if (Character.isLowerCase(c)) return "Lowercase";
        return "Not an alphabet";
    }
}
