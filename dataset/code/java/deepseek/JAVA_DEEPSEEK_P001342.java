import java.util.*;

public class Main {
    static List<String> result = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        backtrack(arr, K, 0, "");
        Collections.sort(result);
        for (String s : result) {
            System.out.println(s);
        }
    }

    private static void backtrack(int[] arr, int k, int start, String curr) {
        if (curr.length() == k) {
            result.add(curr);
            return;
        }
        for (int i = start; i < arr.length; i++) {
            curr += arr[i];
            backtrack(arr, k, i + 1, curr);
            curr = curr.substring(0, curr.length() - 1);
        }
    }
}
