import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] arr1 = new int[N];
        for (int i = 0; i < N; i++) {
            arr1[i] = scanner.nextInt();
        }

        int M = scanner.nextInt();
        int[] arr2 = new int[M];
        for (int i = 0; i < M; i++) {
            arr2[i] = scanner.nextInt();
        }

        mergeSortedArrays(arr1, arr2);
    }

    private static void mergeSortedArrays(int[] arr1, int[] arr2) {
        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                System.out.print(arr1[i++] + " ");
            } else {
                System.out.print(arr2[j++] + " ");
            }
        }
        while (i < arr1.length) {
            System.out.print(arr1[i++] + " ");
        }
        while (j < arr2.length) {
            System.out.print(arr2[j++] + " ");
        }
        System.out.println();
    }
}
