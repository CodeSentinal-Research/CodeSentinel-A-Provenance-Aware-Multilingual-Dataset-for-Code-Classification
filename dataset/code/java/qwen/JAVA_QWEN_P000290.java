import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        String pattern = sc.next();
        
        List<Integer> result = new ArrayList<>();
        int[] pCounts = new int[26];
        int[] tCounts = new int[26];
        
        for (char c : pattern.toCharArray()) {
            pCounts[c - 'a']++;
        }
        
        int pLen = pattern.length();
        for (int i = 0; i < text.length(); i++) {
            tCounts[text.charAt(i) - 'a']++;
            
            if (i >= pLen) {
                tCounts[text.charAt(i - pLen) - 'a']--;
            }
            
            if (i >= pLen - 1) {
                if (java.util.Arrays.equals(pCounts, tCounts)) {
                    result.add(i - pLen + 1);
                }
            }
        }
        
        for (int idx : result) {
            System.out.print(idx + " ");
        }
    }
}
