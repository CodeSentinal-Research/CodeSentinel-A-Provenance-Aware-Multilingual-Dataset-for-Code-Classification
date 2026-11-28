import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] piles = new int[n];
        for(int i=0; i<n; i++) piles[i] = sc.nextInt();
        
        // Stone Game I always returns true for even length with optimal play
        System.out.println("YES");
    }
}
