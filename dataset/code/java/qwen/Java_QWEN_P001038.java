import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] capital = new int[n];
        int[] profit = new int[n];
        for(int i=0; i<n; i++) capital[i] = sc.nextInt();
        for(int i=0; i<n; i++) profit[i] = sc.nextInt();
        int w = sc.nextInt();
        
        PriorityQueue<int[]> minCap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for(int i=0; i<n; i++) minCap.offer(new int[]{capital[i], profit[i]});
        
        PriorityQueue<Integer> maxProf = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0; i<k; i++) {
            while(!minCap.isEmpty() && minCap.peek()[0] <= w) {
                maxProf.offer(minCap.poll()[1]);
            }
            if(maxProf.isEmpty()) break;
            w += maxProf.poll();
        }
        System.out.println(w);
    }
}
