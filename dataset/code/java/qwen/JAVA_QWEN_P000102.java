import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int minVal = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            if (val < minVal) minVal = val;
        }
        System.out.println(minVal);
    }
}
