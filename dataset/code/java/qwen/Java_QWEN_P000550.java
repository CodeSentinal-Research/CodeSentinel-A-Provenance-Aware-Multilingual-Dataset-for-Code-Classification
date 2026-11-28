import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] petrol = new int[n];
        int[] distance = new int[n];
        for(int i=0; i<n; i++) petrol[i] = sc.nextInt();
        for(int i=0; i<n; i++) distance[i] = sc.nextInt();
        
        int start = 0, total = 0, tank = 0;
        for(int i=0; i<n; i++) {
            tank += petrol[i] - distance[i];
            total += petrol[i] - distance[i];
            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        System.out.println(total >= 0 ? start : -1);
    }
}
