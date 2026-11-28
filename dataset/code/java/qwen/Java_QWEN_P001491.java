import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] scores = new int[n];
        for(int i=0; i<n; i++) scores[i] = sc.nextInt();
        
        Arrays.sort(scores);
        int minDiff = Integer.MAX_VALUE;
        for(int i=0; i<=n-k; i++) {
            minDiff = Math.min(minDiff, scores[i+k-1] - scores[i]);
        }
        System.out.println(minDiff);
    }
}
