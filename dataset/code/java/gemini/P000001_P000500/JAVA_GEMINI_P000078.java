import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int d = scanner.nextInt();
            int y = d / 365;
            int rem = d % 365;
            int w = rem / 7;
            int days = rem % 7;
            System.out.println(y + " Years " + w + " Weeks " + days + " Days");
        }
    }
}