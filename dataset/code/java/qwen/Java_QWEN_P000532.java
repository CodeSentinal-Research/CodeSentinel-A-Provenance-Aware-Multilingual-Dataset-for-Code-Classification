import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] tickets = new int[n];
        for(int i=0; i<n; i++) tickets[i] = sc.nextInt();
        int k = sc.nextInt();
        
        int time = 0;
        while(tickets[k] > 0) {
            for(int i=0; i<n; i++) {
                if(tickets[i] > 0) {
                    tickets[i]--;
                    time++;
                    if(tickets[k] == 0) break;
                }
            }
        }
        System.out.println(time);
    }
}
