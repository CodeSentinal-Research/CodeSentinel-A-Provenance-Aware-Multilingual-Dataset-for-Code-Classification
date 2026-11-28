import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] plantTime = new int[n];
        int[] growTime = new int[n];
        for(int i=0; i<n; i++) plantTime[i] = sc.nextInt();
        for(int i=0; i<n; i++) growTime[i] = sc.nextInt();
        
        int[][] flowers = new int[n][2];
        for(int i=0; i<n; i++) {
            flowers[i][0] = plantTime[i];
            flowers[i][1] = growTime[i];
        }
        Arrays.sort(flowers, (a, b) -> b[1] - a[1]);
        
        int currentTime = 0;
        int maxBloom = 0;
        for(int[] flower : flowers) {
            currentTime += flower[0];
            maxBloom = Math.max(maxBloom, currentTime + flower[1]);
        }
        System.out.println(maxBloom);
    }
}
