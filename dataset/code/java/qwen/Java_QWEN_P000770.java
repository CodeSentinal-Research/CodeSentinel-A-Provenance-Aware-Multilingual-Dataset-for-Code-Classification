import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dims = new int[n];
        for(int i=0; i<n; i++) dims[i] = sc.nextInt();
        System.out.println(mcm(dims, 1, n-1));
    }
    static long mcm(int[] dims, int i, int j) {
        if(i >= j) return 0;
        long min = Long.MAX_VALUE;
        for(int k=i; k<j; k++) {
            long cost = mcm(dims, i, k) + mcm(dims, k+1, j) + (long)dims[i-1]*dims[k]*dims[j];
            min = Math.min(min, cost);
        }
        return min;
    }
}
