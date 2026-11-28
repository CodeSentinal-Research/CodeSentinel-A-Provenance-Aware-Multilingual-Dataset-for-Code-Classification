import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] seats = new int[N];
        for (int i = 0; i < N; i++) {
            seats[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxDistance(seats));
    }

    public static int maxDistance(int[] seats) {
        int n = seats.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int maxDistance = 0;
        int maxDistanceHere = 0;
        int leftIndex = 0;
        int rightIndex = n - 1;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                left[i] = 0;
            } else {
                left[i] = (i == 0) ? 0 : Math.min(left[i - 1], maxDistanceHere + 1);
                maxDistanceHere++;
            }
        }

        maxDistanceHere = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 0) {
                right[i] = 0;
            } else {
                right[i] = (i == n - 1) ? 0 : Math.min(right[i + 1], maxDistanceHere + 1);
                maxDistanceHere++;
            }
        }

        for (int i = 0; i < n; i++) {
            maxDistance = Math.max(maxDistance, left[i] + right[i]);
        }

        return maxDistance;
    }
}
