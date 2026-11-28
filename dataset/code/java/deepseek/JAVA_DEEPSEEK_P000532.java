import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] tickets = new int[n];
        for (int i = 0; i < n; i++) {
            tickets[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(timeRequiredToBuy(tickets, k));
    }

    public static int timeRequiredToBuy(int[] tickets, int k) {
        int time = 0;
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                time += Math.min(tickets[i], tickets[k]);
           } else {
                time += Math.min(tickets[i], tickets[k] - 1);
            }
        }
        return time;
    }
}
