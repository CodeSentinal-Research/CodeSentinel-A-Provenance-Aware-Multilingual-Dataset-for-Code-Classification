import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] jobs = new int[n][2];
        for(int i=0; i<n; i++) {
            jobs[i][0] = sc.nextInt();
            jobs[i][1] = sc.nextInt();
        }
        
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        
        int count = 1;
        int lastEnd = jobs[0][1];
        for(int i=1; i<n; i++) {
            if(jobs[i][0] >= lastEnd) {
                count++;
                lastEnd = jobs[i][1];
            }
        }
        System.out.println(count);
    }
}
