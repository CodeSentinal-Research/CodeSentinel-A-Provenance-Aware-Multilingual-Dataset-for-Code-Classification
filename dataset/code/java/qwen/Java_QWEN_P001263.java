import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] costs = new int[2*n][2];
        for(int i=0; i<2*n; i++) {
            costs[i][0] = sc.nextInt();
            costs[i][1] = sc.nextInt();
        }
        
        Arrays.sort(costs, (a, b) -> (a[0] - a[1]) - (b[0] - b[1]));
        
        int totalCost = 0;
        for(int i=0; i<n; i++) totalCost += costs[i][0];
        for(int i=n; i<2*n; i++) totalCost += costs[i][1];
        
        System.out.println(totalCost);
    }
}
