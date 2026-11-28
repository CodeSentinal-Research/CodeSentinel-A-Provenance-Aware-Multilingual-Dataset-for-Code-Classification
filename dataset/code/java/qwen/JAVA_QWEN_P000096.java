import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int temp = n;
        int sum = 0;
        int prod = 1;
        while (temp > 0) {
            sum += temp % 10;
            prod *= temp % 10;
            temp /= 10;
        }
        System.out.println(sum == prod ? "Spy" : "Not Spy");
    }
}
