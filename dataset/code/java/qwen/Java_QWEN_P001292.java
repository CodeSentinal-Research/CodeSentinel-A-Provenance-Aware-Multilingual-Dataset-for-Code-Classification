import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dist = new int[n];
        int[] speed = new int[n];
        for(int i=0; i<n; i++) dist[i] = sc.nextInt();
        for(int i=0; i<n; i++) speed[i] = sc.nextInt();
        
        double[] time = new double[n];
        for(int i=0; i<n; i++) time[i] = (double)dist[i] / speed[i];
        Arrays.sort(time);
        
        int killed = 0;
        for(int i=0; i<n; i++) {
            if(time[i] > i) killed++;
            else break;
        }
        System.out.println(killed);
    }
}
