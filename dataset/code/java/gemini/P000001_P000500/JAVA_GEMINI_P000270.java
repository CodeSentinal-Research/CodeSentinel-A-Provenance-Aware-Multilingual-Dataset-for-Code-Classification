public class Solution {
    public String capitalize(String s) {
        char[] arr = s.toCharArray();
        boolean newWord = true;
        for (int i = 0; i < arr.length; i++) {
            if (Character.isWhitespace(arr[i])) {
                newWord = true;
            } else if (newWord) {
                arr[i] = Character.toUpperCase(arr[i]);
                newWord = false;
            }
        }
        return new String(arr);
    }
}