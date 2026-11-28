import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int coins = sc.nextInt();
        int[] costs = new int[n];
        for(int i=0; i<n; i++) costs[i] = sc.nextInt();
        
        Arrays.sort(costs);
        int count = 0;
        for(int cost : costs) {
            if(coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        System.out.println(count);
    }
}
