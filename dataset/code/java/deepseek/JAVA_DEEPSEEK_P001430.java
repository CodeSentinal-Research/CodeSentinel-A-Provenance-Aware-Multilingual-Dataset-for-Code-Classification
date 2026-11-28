import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        scanner.close();
        int[] result = findPrefixCommonArray(a, b);
        System.out.println(Arrays.toString(result));
    }

    public static int[] findPrefixCommonArray(int[] a, int[] b) {
        int n = a.length;
        int[] result = new int[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                count++;
            } else {
                count = 0;
            }
            result[i] = count;
        }
        return result;
    }
}
