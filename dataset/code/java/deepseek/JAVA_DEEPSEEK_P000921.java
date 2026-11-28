import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        int[] freq = new int[10];
        
        while (n > 0) {
            freq[(int)(n % 10)]++;
            n /= 10;
        }
        
        for (int i = 0; i < 10; i++) {
            System.out.print(freq[i] + " ");
        }
    }
}
