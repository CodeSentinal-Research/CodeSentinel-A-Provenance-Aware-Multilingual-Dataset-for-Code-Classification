import java.util.Scanner;
public class Solution {
    public int add(int a, int b) {
        return a + b;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();
        System.out.println(new Solution().add(a, b));
    }
}
