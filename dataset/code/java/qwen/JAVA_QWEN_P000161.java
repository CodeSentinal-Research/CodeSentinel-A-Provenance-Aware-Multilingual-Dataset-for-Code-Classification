import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        TreeSet<String> pairs = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target) {
                    int min = Math.min(arr[i], arr[j]);
                    int max = Math.max(arr[i], arr[j]);
                    pairs.add(min + " " + max);
                }
            }
        }
        
        for (String pair : pairs) {
            System.out.println(pair);
        }
    }
}
