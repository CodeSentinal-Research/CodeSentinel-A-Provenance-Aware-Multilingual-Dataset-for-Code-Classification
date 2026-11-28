import java.util.*;
public class Solution {
    static void genKStrings(char[] chars, int k, String cur) {
        if (cur.length() == k) {
            System.out.println(cur);
            return;
        }
        for (char c : chars) {
            genKStrings(chars, k, cur + c);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            char[] chars = new char[n];
            for (int i = 0; i < n; i++) chars[i] = scanner.next().charAt(0);
            int k = scanner.nextInt();
            Arrays.sort(chars);
            genKStrings(chars, k, "");
        }
    }
}