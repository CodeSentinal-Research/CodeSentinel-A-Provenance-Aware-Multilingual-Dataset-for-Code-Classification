import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        genAbbr(word, 0, new StringBuilder(), 0);
    }
    
    static void genAbbr(String word, int i, StringBuilder curr, int count) {
        if(i == word.length()) {
            if(count > 0) curr.append(count);
            System.out.println(curr.toString());
            return;
        }
        
        // Abbreviate
        genAbbr(word, i+1, curr, count+1);
        
        // Keep character
        int len = curr.length();
        if(count > 0) curr.append(count);
        curr.append(word.charAt(i));
        genAbbr(word, i+1, curr, 0);
        curr.setLength(len);
    }
}
