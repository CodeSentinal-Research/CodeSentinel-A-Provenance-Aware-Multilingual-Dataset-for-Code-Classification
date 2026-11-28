import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        int min = Integer.MAX_VALUE;
        min = Math.min(min, freq['b'-'a']);
        min = Math.min(min, freq['a'-'a']);
        min = Math.min(min, freq['l'-'a']);
        min = Math.min(min, freq['o'-'a'] / 2);
        min = Math.min(min, freq['n'-'a']);
        
        System.out.println(min);
    }
}
