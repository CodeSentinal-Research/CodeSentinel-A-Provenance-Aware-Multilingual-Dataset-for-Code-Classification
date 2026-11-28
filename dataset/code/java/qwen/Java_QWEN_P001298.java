import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] weeks = new int[n];
        for(int i=0; i<n; i++) weeks[i] = sc.nextInt();
        
        long total = 0;
        long maxWeeks = 0;
        for(int w : weeks) {
            total += w;
            maxWeeks = Math.max(maxWeeks, w);
        }
        
        if(maxWeeks > total - maxWeeks) {
            System.out.println(2 * (total - maxWeeks) + 1);
        } else {
            System.out.println(total);
        }
    }
}
