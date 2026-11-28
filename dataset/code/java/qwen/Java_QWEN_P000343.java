import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String w1 = sc.next();
        String w2 = sc.next();
        int[] c1 = new int[26];
        int[] c2 = new int[26];
        for (char c : w1.toCharArray()) c1[c - 'a']++;
        for (char c : w2.toCharArray()) c2[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (Math.abs(c1[i] - c2[i]) > 3) {
                System.out.println("No"); return;
            }
        }
        System.out.println("Yes");
    }
}
