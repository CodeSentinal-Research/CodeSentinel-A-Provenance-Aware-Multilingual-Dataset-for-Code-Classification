import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String attendance = scanner.next();
        if (attendance.contains("LLL") || attendance.indexOf('A') != -1 && attendance.indexOf('A') < attendance.lastIndexOf('A') + 2) {
            System.out.println("No");
       } else {
            System.out.println("Yes");
        }
    }
}
