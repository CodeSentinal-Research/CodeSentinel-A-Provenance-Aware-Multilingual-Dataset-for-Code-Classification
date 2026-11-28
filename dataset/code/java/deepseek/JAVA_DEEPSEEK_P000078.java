import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int days = scanner.nextInt();
        int years = days / 365;
        days %= 365;
        int weeks = days / 7;
        days %= 7;
        System.out.println(years + " years, " + weeks + " weeks, and " + days + " days.");
    }
}
