import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int xorSum = 0;
        for (int i = 0; i < n; i++) {
            xorSum ^= sc.nextInt();
        }
        System.out.println(xorSum);
    }
}
