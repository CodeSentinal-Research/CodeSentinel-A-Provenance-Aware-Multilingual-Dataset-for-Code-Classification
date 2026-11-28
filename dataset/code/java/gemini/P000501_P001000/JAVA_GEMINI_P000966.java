import java.util.Scanner;

public class Solution {
    public static boolean verifyCrt(long x, long[] num, long[] rem) {
        for (int i = 0; i < num.length; i++) {
            if (x % num[i] != rem[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long x = sc.nextLong();
            int k = sc.nextInt();
            long[] num = new long[k];
            for (int i = 0; i < k; i++) num[i] = sc.nextLong();
            long[] rem = new long[k];
            for (int i = 0; i < k; i++) rem[i] = sc.nextLong();
            System.out.println(verifyCrt(x, num, rem) ? "YES" : "NO");
        }
        sc.close();
    }
}