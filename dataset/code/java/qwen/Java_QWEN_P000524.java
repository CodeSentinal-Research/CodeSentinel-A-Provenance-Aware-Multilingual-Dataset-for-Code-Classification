import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] maxHeights = new int[n];
        for(int i=0; i<n; i++) maxHeights[i] = sc.nextInt();
        
        long maxSum = 0;
        for(int i=0; i<n; i++) {
            long sum = 0;
            long h = maxHeights[i];
            for(int j=i; j>=0; j--) {
                h = Math.min(h, maxHeights[j]);
                sum += h;
            }
            h = maxHeights[i];
            for(int j=i+1; j<n; j++) {
                h = Math.min(h, maxHeights[j]);
                sum += h;
            }
            maxSum = Math.max(maxSum, sum);
        }
        System.out.println(maxSum);
    }
}
