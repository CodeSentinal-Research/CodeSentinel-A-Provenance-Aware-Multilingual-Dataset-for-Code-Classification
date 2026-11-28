import java.util.Scanner;
public class Solution {
    public String evenOdd(int n) { return n % 2 == 0 ? "Even" : "Odd"; }
    public static void main(String[] args) {
        System.out.println(new Solution().evenOdd(new Scanner(System.in).nextInt()));
    }
}
