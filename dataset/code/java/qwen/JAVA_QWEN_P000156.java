import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int maxConsecutive = 0;
        int current = 0;
        
        for (int i = 0; i < n; i++) {
            if (sc.nextInt() == 0) {
                current++;
                maxConsecutive = Math.max(maxConsecutive, current);
            } else {
                current = 0;
            }
        }
        System.out.println(maxConsecutive);
    }
}
