import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Meeting> meetings = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            meetings.add(new Meeting(start, end));
        }
        scanner.close();
        System.out.println(minMeetingRooms(meetings));
    }

    public static int minMeetingRooms(List<Meeting> meetings) {
        List<Integer> rooms = new ArrayList<>();
        Collections.sort(meetings, Comparator.comparingInt(m -> m.end));
        for (Meeting meeting : meetings) {
            if (rooms.isEmpty() || rooms.get(0) <= meeting.start) {
                rooms.remove(0);
            } else {
                Collections.rotate(rooms, -1);
            }
            rooms.add(meeting.end);
        }
        return rooms.size();
    }

    static class Meeting {
        int start;
        int end;

        Meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
