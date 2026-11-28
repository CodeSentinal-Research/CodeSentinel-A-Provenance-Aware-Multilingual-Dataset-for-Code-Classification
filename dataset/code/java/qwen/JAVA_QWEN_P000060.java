import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int count = 0;
        do {
            if ((n % 10) % 2 == 0) count++;
            n /= 10;
        } while (n > 0);
        System.out.println(count);
    }
}
