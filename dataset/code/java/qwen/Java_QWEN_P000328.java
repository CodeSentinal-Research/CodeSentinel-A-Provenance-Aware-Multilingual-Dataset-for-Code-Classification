import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] counts = new int[256];
        for (char c : s.toCharArray()) counts[c]++;
        for (int i = 0; i < s.length(); i++) {
            if (counts[s.charAt(i)] == 1) {
                System.out.println(i); return;
            }
        }
        System.out.println("-1");
    }
}
