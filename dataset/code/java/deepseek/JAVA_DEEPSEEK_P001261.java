import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int target = scanner.nextInt();
        int startFuel = scanner.nextInt();
        int n = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int position = scanner.nextInt();
            int fuel = scanner.nextInt();
            queue.add(fuel);
        }
        System.out.println(minRefuelingStops(target, startFuel, queue));
    }

    public static int minRefuelingStops(int target, int startFuel, PriorityQueue<Integer> queue) {
        if (startFuel >= target) {
            return 0;
        }
        int stops = 0;
        while (!queue.isEmpty() && startFuel < target) {
            startFuel += queue.poll();
            stops++;
        }
        if (startFuel >= target) {
            return stops;
        }
        return -1;
    }
}
