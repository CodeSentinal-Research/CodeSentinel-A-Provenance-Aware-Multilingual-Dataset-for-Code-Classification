import java.util.*;

public class Main {
    static class Station {
        int position;
        int fuel;

        Station(int position, int fuel) {
            this.position = position;
            this.fuel = fuel;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int distance = scanner.nextInt();
        int initialFuel = scanner.nextInt();
        int numStations = scanner.nextInt();
        List<Station> stations = new ArrayList<>();
        for (int i = 0; i < numStations; i++) {
            stations.add(new Station(scanner.nextInt(), scanner.nextInt()));
        }
        scanner.close();

        System.out.println(minRefuelingStops(distance, initialFuel, stations));
    }

    public static int minRefuelingStops(int target, int initialFuel, List<Station> stations) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        maxHeap.add(initialFuel);
        int stops = 0;
        int currPos = 0;

        while (currPos < target) {
            if (maxHeap.isEmpty()) {
                return -1;
            }
            currPos += maxHeap.poll();
            stops++;
            for (Station station : stations) {
                if (station.position <= currPos) {
                    maxHeap.add(station.fuel);
                }
            }
        }
        return stops;
    }
}
