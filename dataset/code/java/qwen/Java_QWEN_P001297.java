import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];
        for(int i=0; i<n; i++) A[i] = sc.nextInt();
        for(int i=0; i<n; i++) B[i] = sc.nextInt();
        
        long sumA = 0;
        for(int a : A) sumA += a;
        
        int maxGain = 0;
        for(int i=0; i<n; i++) {
            maxGain = Math.max(maxGain, B[i] - A[i]);
        }
        System.out.println(sumA + maxGain);
    }
}
