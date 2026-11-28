import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] bills = new int[n];
        for(int i=0; i<n; i++) bills[i] = sc.nextInt();
        
        int five = 0, ten = 0;
        for(int bill : bills) {
            if(bill == 5) five++;
            else if(bill == 10) {
                if(five == 0) { System.out.println("NO"); return; }
                five--; ten++;
            } else {
                if(ten > 0 && five > 0) { ten--; five--; }
                else if(five >= 3) { five -= 3; }
                else { System.out.println("NO"); return; }
            }
        }
        System.out.println("YES");
    }
}
