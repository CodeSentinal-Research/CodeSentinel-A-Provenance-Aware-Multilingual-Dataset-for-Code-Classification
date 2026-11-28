import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] pages = new int[n];
        for (int i = 0; i < n; i++) {
            pages[i] = sc.nextInt();
        }
        System.out.println(findPages(pages, n, m));
    }

    static int findPages(int[] pages, int n, int m) {
        long sum = 0;
        long max = 0;
        for (int i = 0; i < n; i++) {
            sum += pages[i];
            max = Math.max(max, pages[i]);
        }
        long start = max;
        long end = sum;
        long res = -1;
        while (start <= end) {
            long mid = (start + end) / 2;
            if (isValid(pages, n, m, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return (int)res;
    }

    static boolean isValid(int[] pages, int n, int m, long max) {
        long sum = 0;
        int students = 1;
        for (int i = 0; i < n; i++) {
            if (sum + pages[i] > max) {
                sum = pages[i];
                students++;
                if (students > m) {
                    return false;
                }
            } else {
                sum += pages[i];
            }
        }
        return true;
    }
}
