import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] packets = new int[n];
        for (int i = 0; i < n; i++) {
            packets[i] = sc.nextInt();
        }
        
        Arrays.sort(packets);
        int minDiff = Integer.MAX_VALUE;
        
        for (int i = 0; i <= n - k; i++) {
            int diff = packets[i + k - 1] - packets[i];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        System.out.println(minDiff);
    }
}
