import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long total = 0;
            for (int i = 0; i < n; i++) total += scanner.nextLong();
            System.out.println(total);
        }
    }
}