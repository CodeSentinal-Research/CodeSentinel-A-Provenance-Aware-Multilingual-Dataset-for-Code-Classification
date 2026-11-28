import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long evenCount = 0;
        long oddCount = 0;
        while (n > 0) {
            long digit = n % 10;
            if (digit % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
           }
        }
        System.out.println(evenCount + " " + oddCount);
    }
}
