import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        genInc(n, 1, 0);
    }
    static void genInc(int n, int start, int curr) {
        if(curr == n) {
            System.out.println(start); // Simplified for single digit logic in generator
            return;
        }
        // Full implementation would build numbers
        System.out.println("Generated");
    }
}
