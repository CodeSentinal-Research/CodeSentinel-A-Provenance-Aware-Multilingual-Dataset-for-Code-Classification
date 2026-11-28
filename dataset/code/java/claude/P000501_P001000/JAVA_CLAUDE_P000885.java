import java.util.Scanner;
public class Solution {
    public boolean isArmstrong(int n) {
        int temp = n, digits = 0, sum = 0;
        while (temp > 0) { digits++; temp /= 10; }
        temp = n;
        while (temp > 0) { int d = temp % 10; sum += (int) Math.pow(d, digits); temp /= 10; }
        return sum == n;
    }
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        System.out.println(new Solution().isArmstrong(n) ? "Armstrong" : "Not Armstrong");
    }
}
