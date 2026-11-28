import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ransom = sc.next();
        String mag = sc.next();
        int[] counts = new int[26];
        for (char c : mag.toCharArray()) counts[c - 'a']++;
        for (char c : ransom.toCharArray()) {
            if (--counts[c - 'a'] < 0) {
                System.out.println("No"); return;
            }
        }
        System.out.println("Yes");
    }
}
