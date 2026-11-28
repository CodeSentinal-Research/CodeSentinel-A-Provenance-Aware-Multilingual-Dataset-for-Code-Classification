import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        ArrayList<Pair> trains = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            trains.add(new Pair(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }

        Collections.sort(trains, Comparator.comparing((Pair p) -> p.arrival).thenComparing(p -> p.departure));

        PriorityQueue<Integer> platforms = new PriorityQueue<>();
        platforms.add(trains.get(0).departure);
        int minPlatforms = 1;

        for (int i = 1; i < trains.size(); i++) {
            if (trains.get(i).arrival < platforms.peek()) {
                platforms.poll();
            }
            platforms.add(trains.get(i).departure);
            minPlatforms = Math.max(minPlatforms, platforms.size());
        }

        System.out.println(minPlatforms);
    }

    static class Pair {
        int arrival;
        int departure;

        Pair(int arrival, int departure) {
            this.arrival = arrival;
            this.departure = departure;
        }
    }
}
