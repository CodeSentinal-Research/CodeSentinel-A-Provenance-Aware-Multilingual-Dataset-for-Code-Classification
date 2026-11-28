import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int s = scanner.nextInt();
            int h = s / 3600;
            int rem = s % 3600;
            int m = rem / 60;
            int sec = rem % 60;
            System.out.println(h + " Hours " + m + " Minutes " + sec + " Seconds");
        }
    }
}