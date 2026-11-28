import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        int maxD = 0, minD = 9;
        if(n == 0) { System.out.println("0 0"); return; }
        while(n > 0) {
            int d = (int)(n % 10);
            maxD = Math.max(maxD, d);
            minD = Math.min(minD, d);
            n /= 10;
        }
        System.out.println(maxD + " " + minD);
    }
}
