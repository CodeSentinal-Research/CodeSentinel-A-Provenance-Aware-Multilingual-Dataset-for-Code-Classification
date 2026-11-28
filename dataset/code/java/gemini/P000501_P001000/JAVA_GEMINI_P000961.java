import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong(), b = sc.nextLong(), c = sc.nextLong();
            long minx = sc.nextLong(), maxx = sc.nextLong(), miny = sc.nextLong(), maxy = sc.nextLong();
            long count = 0;
            for (long x = minx; x <= maxx; x++) {
                long rem = c - a * x;
                if (rem % b == 0) {
                    long y = rem / b;
                    if (y >= miny && y <= maxy) count++;
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}