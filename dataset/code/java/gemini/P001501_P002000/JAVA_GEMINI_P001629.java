import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long cur = 0;
            int longest = 0;
            for (int i = 0; i < n; i++) {
                cur += sc.nextInt();
                if (cur < 0) longest = i + 1;
            }
            System.out.println(longest);
        }
        sc.close();
    }
}