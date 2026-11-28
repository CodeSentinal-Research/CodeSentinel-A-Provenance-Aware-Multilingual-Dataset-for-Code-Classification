import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] weights = new int[n];
        for(int i=0; i<n; i++) weights[i] = sc.nextInt();
        
        int[] cuts = new int[n-1];
        for(int i=0; i<n-1; i++) cuts[i] = weights[i] + weights[i+1];
        Arrays.sort(cuts);
        
        long minScore = 0, maxScore = 0;
        for(int i=0; i<k-1; i++) minScore += cuts[i];
        for(int i=n-2; i>n-k; i--) maxScore += cuts[i];
        
        System.out.println(maxScore - minScore);
    }
}
