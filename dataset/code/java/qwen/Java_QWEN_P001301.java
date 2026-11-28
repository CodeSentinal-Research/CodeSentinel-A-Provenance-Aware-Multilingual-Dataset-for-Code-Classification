import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] meetings = new int[n][2];
        for(int i=0; i<n; i++) {
            meetings[i][0] = sc.nextInt();
            meetings[i][1] = sc.nextInt();
        }
        
        Arrays.sort(meetings, (a, b) -> a[1] - b[1]);
        
        int count = 1;
        int lastEnd = meetings[0][1];
        for(int i=1; i<n; i++) {
            if(meetings[i][0] >= lastEnd) {
                count++;
                lastEnd = meetings[i][1];
            }
        }
        System.out.println(count);
    }
}
