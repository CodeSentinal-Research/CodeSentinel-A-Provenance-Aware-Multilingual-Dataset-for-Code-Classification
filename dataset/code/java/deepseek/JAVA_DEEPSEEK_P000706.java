import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        
        generateBinary(n, "");
    }
    
    private static void generateBinary(int n, String s) {
        if (n == 0) {
            System.out.println(s);
        } else {
            generateBinary(n - 1, s + "0");
            generateBinary(n - 1, s + "1");
        }
    }
}
