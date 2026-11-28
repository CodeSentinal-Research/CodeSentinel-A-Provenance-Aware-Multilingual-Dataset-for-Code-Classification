import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        int[] temp = new int[n];
        int low = 0, high = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                temp[i] = arr[high--];
            } else {
                temp[i] = arr[low++];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(temp[i]);
        }
        System.out.println();
    }
}
