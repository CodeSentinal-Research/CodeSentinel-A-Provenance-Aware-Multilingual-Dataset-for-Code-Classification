import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(climbStairs(n));
    }
    static int climbStairs(int n) {
        if(n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}
