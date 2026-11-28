import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Job[] jobs = new Job[n];
        for(int i=0; i<n; i++) {
            jobs[i] = new Job(i+1, sc.nextInt(), sc.nextInt());
        }
        
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);
        
        int maxDeadline = 0;
        for(Job job : jobs) maxDeadline = Math.max(maxDeadline, job.deadline);
        
        int[] result = new int[maxDeadline + 1];
        Arrays.fill(result, -1);
        
        int count = 0, profit = 0;
        for(Job job : jobs) {
            for(int j=Math.min(maxDeadline, job.deadline); j>0; j--) {
                if(result[j] == -1) {
                    result[j] = job.id;
                    count++;
                    profit += job.profit;
                    break;
                }
            }
        }
        System.out.println(profit);
    }
}
class Job {
    int id, deadline, profit;
    Job(int i, int d, int p) { id = i; deadline = d; profit = p; }
}
