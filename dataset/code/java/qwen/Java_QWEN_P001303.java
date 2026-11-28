import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int initialCapital = sc.nextInt();
        
        int[][] projects = new int[n][2];
        for(int i=0; i<n; i++) {
            projects[i][0] = sc.nextInt(); // capital
            projects[i][1] = sc.nextInt(); // profit
        }
        
        PriorityQueue<int[]> minCap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> maxProf = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        
        for(int[] p : projects) minCap.offer(p);
        
        int capital = initialCapital;
        for(int i=0; i<k; i++) {
            while(!minCap.isEmpty() && minCap.peek()[0] <= capital) {
                maxProf.offer(minCap.poll());
            }
            if(maxProf.isEmpty()) break;
            capital += maxProf.poll()[1];
        }
        System.out.println(capital);
    }
}
