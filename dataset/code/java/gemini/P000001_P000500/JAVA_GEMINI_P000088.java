import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            if (n < 0) { System.out.println("Not Perfect Square"); return; }
            long sq = (long) Math.sqrt(n);
            System.out.println(sq * sq == n ? "Perfect Square" : "Not Perfect Square");
        }
    }
}