import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long target = scanner.nextLong();
            int idx = -1;
            for (int i = 0; i < n; i++) {
                long val = scanner.nextLong();
                if (val == target && idx == -1) idx = i;
            }
            System.out.println(idx);
        }
    }
}