import java.util.Scanner;
public class Solution {
    public long factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        System.out.println(new Solution().factorial(n));
    }
}
