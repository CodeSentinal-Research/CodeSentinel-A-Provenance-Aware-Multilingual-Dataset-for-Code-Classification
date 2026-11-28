import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) prices[i] = sc.nextInt();
        
        if (n == 0) { System.out.println(0); return; }
        
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        
        for (int i = 1; i < n; i++) {
            int prevHold = hold;
            hold = Math.max(hold, rest - prices[i]);
            rest = Math.max(rest, sold);
            sold = prevHold + prices[i];
        }
        System.out.println(Math.max(sold, rest));
    }
}
