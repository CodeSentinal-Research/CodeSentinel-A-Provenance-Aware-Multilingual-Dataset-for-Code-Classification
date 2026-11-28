import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            long cur = 0;
            for (int i = 0; i < s.length(); i++) {
                cur += s.charAt(i) - 'a' + 1;
                System.out.print(cur + (i == s.length() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}