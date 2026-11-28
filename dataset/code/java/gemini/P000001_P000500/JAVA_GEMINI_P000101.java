import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long maxVal = Long.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                long val = scanner.nextLong();
                if (val > maxVal) maxVal = val;
            }
            System.out.println(maxVal);
        }
    }
}