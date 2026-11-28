import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        for(int i=0; i<n; i++) b[i] = sc.nextInt();
        
        long ops = 0;
        long sumA = 0;
        long sumB = 0;
        for(int i=0; i<n; i++) {
            sumA += a[i];
            sumB += b[i];
            if(sumA < sumB) {
                ops += (sumB - sumA);
                sumA = sumB;
            }
        }
        System.out.println(ops);
    }
}
