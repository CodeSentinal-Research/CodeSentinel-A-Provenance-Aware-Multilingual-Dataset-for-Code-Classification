import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seats = new int[n];
        for(int i=0; i<n; i++) seats[i] = sc.nextInt();
        
        int maxDist = 0;
        int lastSeat = -1;
        for(int i=0; i<n; i++) {
            if(seats[i] == 1) {
                if(lastSeat == -1) maxDist = i;
                else maxDist = Math.max(maxDist, (i - lastSeat) / 2);
                lastSeat = i;
            }
        }
        if(lastSeat != -1) maxDist = Math.max(maxDist, n - 1 - lastSeat);
        
        System.out.println(maxDist);
    }
}
