import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Course> courses = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int duration = scanner.nextInt();
            int deadline = scanner.nextInt();
            courses.add(new Course(duration, deadline));
        }
        Collections.sort(courses, (a, b) -> b.deadline - a.deadline);
        int maxDeadline = courses.get(0).deadline;
        int count = 0;
        for (Course course : courses) {
            if (course.deadline <= maxDeadline) {
                count++;
                maxDeadline = course.deadline;
            }
        }
        System.out.println(count);
    }

    static class Course {
        int duration;
        int deadline;

        public Course(int duration, int deadline) {
            this.duration = duration;
            this.deadline = deadline;
        }
    }
}
