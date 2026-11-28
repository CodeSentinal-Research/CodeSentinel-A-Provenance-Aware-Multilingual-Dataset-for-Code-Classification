import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] piles = new int[n];
        int sum = 0;
        for(int i=0; i<n; i++) {
            piles[i] = sc.nextInt();
            sum += piles[i];
        }
        // First player always wins in Stone Game I with even length
        System.out.println("true");
    }
}
