import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[] allElements = new int[rows * cols];
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                allElements[idx++] = sc.nextInt();
            }
        }
        
        Arrays.sort(allElements);
        
        idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j > 0) System.out.print(" ");
                System.out.print(allElements[idx++]);
            }
            System.out.println();
        }
    }
}
