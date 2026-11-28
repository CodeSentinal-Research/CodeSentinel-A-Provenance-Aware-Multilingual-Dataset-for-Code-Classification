import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Event> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            events.add(new Event(start, end));
        }
        Collections.sort(events, Comparator.comparingInt(e -> e.end));
        int maxEnd = Integer.MIN_VALUE;
        int count = 0;
        for (Event event : events) {
            if (event.start >= maxEnd) {
                maxEnd = event.end;
                count++;
            }
        }
        System.out.println(count);
    }

    static class Event {
        int start;
        int end;

        Event(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
