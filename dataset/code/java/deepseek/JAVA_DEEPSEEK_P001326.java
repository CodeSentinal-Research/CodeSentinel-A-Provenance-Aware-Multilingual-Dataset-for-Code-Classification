import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n;
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        backtrack(0);
    }

    static void backtrack(int index) {
        if (index == n) {
            printSubset();
            return;
        }
        visited[index] = true;
        backtrack(index + 1);
        visited[index] = false;
        backtrack(index + 1);
    }

    static void printSubset() {
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println();
    }
}
