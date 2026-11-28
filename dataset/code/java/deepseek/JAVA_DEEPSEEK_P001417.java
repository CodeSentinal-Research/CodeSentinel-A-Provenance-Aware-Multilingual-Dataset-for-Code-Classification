import java.util.*;

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
        scanner.close();
        Arrays.sort(arr2);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            map.put(arr1[i], i);
        }
        for (int i = 0; i < M; i++) {
            arr1[i] = map.get(arr2[i]);
        }
        for (int i = 0; i < M; i++) {
            System.out.print(arr1[i] + " ");
        }
    }
}
