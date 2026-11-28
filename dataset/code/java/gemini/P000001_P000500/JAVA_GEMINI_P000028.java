import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String s = String.valueOf(n);
            int p = s.length();
            int sum = 0;
            for (char c : s.toCharArray()) {
                sum += Math.pow(c - '0', p);
            }
            System.out.println(sum == n ? "Armstrong" : "Not Armstrong");
        }
    }
}