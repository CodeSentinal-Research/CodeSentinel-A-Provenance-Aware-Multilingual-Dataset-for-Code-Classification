import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] pages = new int[n];
        for (int i = 0; i < n; i++) {
            pages[i] = sc.nextInt();
        }
        int students = sc.nextInt();
        System.out.println(findPages(pages, n, students));
    }

    static int findPages(int[] pages, int n, int students) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pages[i];
        }
        long start = 0, end = sum;
        long res = Integer.MAX_VALUE;
        while (start <= end) {
            long mid = (start + end) / 2;
            if (isPossible(pages, n, students, mid)) {
                res = Math.min(res, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return (int)res;
    }

    static boolean isPossible(int[] pages, int n, int students, long curr_min) {
        int studentsRequired = 1;
        long curr_sum = 0;
        for (int i = 0; i < n; i++) {
            if (pages[i] > curr_min) {
                return false;
            }
            if (curr_sum + pages[i] > curr_min) {
                curr_sum = pages[i];
                studentsRequired++;
                if (studentsRequired > students) {
                    return false;
                }
            } else {
                curr_sum += pages[i];
            }
        }
        return true;
    }
}
