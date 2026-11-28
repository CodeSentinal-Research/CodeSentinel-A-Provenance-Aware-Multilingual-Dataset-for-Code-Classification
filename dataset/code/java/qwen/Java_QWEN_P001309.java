import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        if(m > n) {
            System.out.println(-1);
            return;
        }
        
        long totalFood = (long)s * m;
        long daysWithPurchase = (totalFood + n - 1) / n;
        
        if(daysWithPurchase > s) {
            System.out.println(-1);
        } else {
            System.out.println(daysWithPurchase);
        }
    }
}
