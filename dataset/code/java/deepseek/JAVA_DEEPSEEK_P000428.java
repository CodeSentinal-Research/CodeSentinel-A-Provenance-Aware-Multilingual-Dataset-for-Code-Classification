import java.io.*;
import java.util.*;

public class Main {
    public static class Event {
        String name;
        String date;

        Event(String name, String date) {
            this.name = name;
            this.date = date;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Event> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            events.add(new Event(input[0], input[1]));
        }
        String targetDate = br.readLine();
        for (Event e : events) {
            if (e.date.equals(targetDate)) {
                System.out.println(e.name);
            }
        }
    }
}
