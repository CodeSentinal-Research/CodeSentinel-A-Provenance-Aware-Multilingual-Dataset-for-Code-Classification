import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        // Height of a complete binary tree with N nodes is floor(log2(N))
        int height = (int)(Math.log(n) / Math.log(2));
        System.out.println(height);
    }
}
