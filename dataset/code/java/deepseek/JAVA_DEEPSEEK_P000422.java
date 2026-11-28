import java.io.*;
import java.util.*;

public class Main {
    public static class Student {
        String name;
        double cgpa;
        int income;

        public Student(String name, double cgpa, int income) {
            this.name = name;
            this.cgpa = cgpa;
            this.income = income;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        double minCgpa = Double.parseDouble(firstLine[1]);
        int maxIncome = Integer.parseInt(firstLine[2]);

        List<Student> students = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] studentDetails = br.readLine().split(" ");
            String name = studentDetails[0];
            double cgpa = Double.parseDouble(studentDetails[1]);
            int income = Integer.parseInt(studentDetails[2]);
            students.add(new Student(name, cgpa, income));
        }

        List<Student> eligibleStudents = new ArrayList<>();
        for (Student student : students) {
            if (student.cgpa >= minCgpa && student.income <= maxIncome) {
                eligibleStudents.add(student);
            }
        }

        for (Student student : eligibleStudents) {
            System.out.println(student.name);
        }
    }
}
