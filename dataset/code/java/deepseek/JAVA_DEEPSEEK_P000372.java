import java.io.*;
import java.util.*;

class Student {
    String name;
    int rollNo;

    Student(String name, int rollNo) {
        this.name = name;
        this.rollNo = rollNo;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        List<Student> studentList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().trim().split(" ");
            String name = inputs[0];
            int rollNo = Integer.parseInt(inputs[1]);
            studentList.add(new Student(name, rollNo));
        }
        int searchRollNo = Integer.parseInt(br.readLine().trim());
        boolean found = false;
        for (Student student : studentList) {
            if (student.rollNo == searchRollNo) {
                System.out.println(student.name + " " + student.rollNo);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Record Not Found");
        }
    }
}
