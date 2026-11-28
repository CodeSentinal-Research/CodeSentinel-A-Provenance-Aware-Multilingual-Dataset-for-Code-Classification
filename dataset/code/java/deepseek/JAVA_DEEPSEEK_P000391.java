import java.io.*;
import java.util.*;

public class Main {
    static class Student {
        String name;
        double gpa;

        Student(String name, double gpa) {
            this.name = name;
            this.gpa = gpa;
        }

        @Override
        public String toString() {
            return name + " " + gpa;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double minGPA = Double.parseDouble(br.readLine());
        List<Student> students = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] data = br.readLine().split(" ");
            students.add(new Student(data[0], Double.parseDouble(data[1])));
        }
        students.stream()
                .filter(s -> s.gpa >= minGPA)
                .forEach(System.out::println);
    }
}
