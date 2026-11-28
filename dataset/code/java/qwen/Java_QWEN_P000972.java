import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        double prob = comb(n, k) / Math.pow(2, n);
        System.out.printf("%.6f
", prob);
    }
    static long comb(int n, int k) {
        if(k > n) return 0;
        long res = 1;
        for(int i=0; i<k; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
}
