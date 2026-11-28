import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String order = sc.next();
        String s = sc.next();
        int[] counts = new int[26];
        for (char c : s.toCharArray()) counts[c - 'a']++;
        StringBuilder sb = new StringBuilder();
        for (char c : order.toCharArray()) {
            while (counts[c - 'a'] > 0) {
                sb.append(c);
                counts[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (counts[i] > 0) {
                sb.append((char)(i + 'a'));
                counts[i]--;
            }
        }
        System.out.println(sb.toString());
    }
}
