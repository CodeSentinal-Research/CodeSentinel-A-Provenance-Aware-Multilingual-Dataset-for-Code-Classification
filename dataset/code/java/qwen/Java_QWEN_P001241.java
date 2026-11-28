import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] gas = new int[n];
        int[] cost = new int[n];
        for(int i=0; i<n; i++) gas[i] = sc.nextInt();
        for(int i=0; i<n; i++) cost[i] = sc.nextInt();
        
        int totalTank = 0, currTank = 0, start = 0;
        for(int i=0; i<n; i++) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if(currTank < 0) {
                start = i + 1;
                currTank = 0;
            }
        }
        System.out.println(totalTank >= 0 ? start : -1);
    }
}
