import java.util.*;

class KeyboardRowSolution {public String[] findWords(String[] words) {
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";
        
        List<String> result = new ArrayList<>();
        
        for (String word : words) {
            String lowerWord = word.toLowerCase();
            
            // Check which row the first character belongs to
            String row = "";
            if (row1.indexOf(lowerWord.charAt(0)) != -1) {
                row = row1;
            } else if (row2.indexOf(lowerWord.charAt(0)) != -1) {
                row = row2;
            } else {
                row = row3;
            }
            
            // Check if all characters belong to the same row
            boolean isValid = true;
            for (char c : lowerWord.toCharArray()) {
                if (row.indexOf(c) == -1) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.add(word);
            }
        }
        
        // Convert List to array
        return result.toArray(new String[0]);
    }
}
public class KeyboardRow {
    public static void main(String[] args) {
        KeyboardRowSolution s = new KeyboardRowSolution();
        String[] result=s.findWords(new String[]{"Hello","Alaska","Dad","Peace"});
    }
}