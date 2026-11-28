import java.util.Scanner;

public class Solution {
    public static String calculateGrade(double marks) {
        if (marks >= 90) return "A";
        else if (marks >= 80) return "B";
        else if (marks >= 70) return "C";
        else if (marks >= 60) return "D";
        else if (marks >= 50) return "E";
        else return "F";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double marks = sc.nextDouble();
            System.out.println(calculateGrade(marks));
        }
        sc.close();
    }
}