import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        if (n == 1) { System.out.println(k); return; }
        if (n == 2) { System.out.println((long)k * k); return; }
        
        long same = k;
        long diff = (long)k * (k - 1);
        
        for (int i = 3; i <= n; i++) {
            long temp = diff;
            diff = (same + diff) * (k - 1);
            same = temp;
        }
        System.out.println(same + diff);
    }
}
