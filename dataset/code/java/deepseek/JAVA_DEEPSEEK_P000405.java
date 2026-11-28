import java.io.*;
import java.util.*;

public class Main {
    static class Course {
        String courseName;
        String instructorName;

        Course(String courseName, String instructorName) {
            this.courseName = courseName;
            this.instructorName = instructorName;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Course> courses = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().split(" ");
            courses.add(new Course(inputs[0], inputs[1]));
        }
        String instructorName = br.readLine();
        for (Course course : courses) {
            if (course.instructorName.equals(instructorName)) {
                System.out.println(course.courseName);
            }
        }
    }
}
