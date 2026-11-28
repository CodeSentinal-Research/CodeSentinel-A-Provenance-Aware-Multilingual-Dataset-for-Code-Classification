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

    private static int maxDistance(int[] seats) {
        int maxDistance = 0;
        int maxDistanceHere = 0;
        int occupiedSeat = -1;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1) {
                if (occupiedSeat != -1) {
                    maxDistanceHere = Math.max(maxDistanceHere, i - occupiedSeat);
                    occupiedSeat = -1;
                }
            } else {
                if (occupiedSeat == -1) {
                    occupiedSeat = i;
                }
            }
        }
        if (occupiedSeat != -1) {
            maxDistanceHere = Math.max(maxDistanceHere, seats.length - occupiedSeat);
        }
        maxDistance = Math.max(maxDistance, maxDistanceHere);
        return maxDistance;
    }
}
