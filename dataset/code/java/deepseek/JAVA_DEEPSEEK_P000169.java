import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(firstRepeatingElement(arr));
    }

    private static int firstRepeatingElement(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int value : arr) {
            if (set.contains(value)) {
                return value;
            }
            set.add(value);
       }
        return -1;
    }
}
