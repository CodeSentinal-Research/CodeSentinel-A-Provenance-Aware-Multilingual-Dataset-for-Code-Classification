import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<Meeting> meetings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            int start = Integer.parseInt(input[0]);
            int end = Integer.parseInt(input[1]);
            meetings.add(new Meeting(start, end));
        }

        Collections.sort(meetings, Comparator.comparingInt(Meeting::getEnd));

        int maxMeetings = 0;
        int end = 0;
        for (Meeting meeting : meetings) {
            if (meeting.getStart() >= end) {
                maxMeetings++;
                end = meeting.getEnd();
            }
        }

        System.out.println(maxMeetings);
    }
}

class Meeting {
    private int start;
    private int end;

    public Meeting(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }
}
