import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // N stones, remove 1..K
        // First player wins if N % (K+1) != 0
        System.out.println(n % (k+1) != 0 ? "FIRST" : "SECOND");
    }
}
