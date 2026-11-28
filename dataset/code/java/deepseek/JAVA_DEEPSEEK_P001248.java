import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int limit = scanner.nextInt();
        int[] weights = new int[N];
        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt();
        }
        Arrays.sort(weights);
        int boats = 0;
        int i = 0;
        while (i < N) {
            int boatWeight = 0;
            while (i < N && boatWeight + weights[i] <= limit) {
                boatWeight += weights[i];
                i++;
            }
            boats++;
        }
        System.out.println(boats);
    }
}
