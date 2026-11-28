import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        // Number of leaves in a complete binary tree
        // If N is even, leaves = N/2. If N is odd, leaves = (N+1)/2
        long leaves = (n + 1) / 2;
        System.out.println(leaves);
    }
}
