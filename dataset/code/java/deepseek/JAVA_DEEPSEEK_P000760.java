import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        
        if (n < 1 || n > 9) {
            return;
        }
        
        generateNumbers(n, 0, "");
    }
    
    private static void generateNumbers(int n, int lastDigit, String number) {
        if (n == 0) {
            System.out.println(number);
            return;
        }
        
        for (int i = lastDigit + 1; i <= 9; i++) {
            generateNumbers(n - 1, i, number + i);
        }
    }
}
