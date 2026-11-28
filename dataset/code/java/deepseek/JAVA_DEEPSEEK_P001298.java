import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] projects = new int[n];
        for (int i = 0; i < n; i++) {
            projects[i] = scanner.nextInt();
        }
        System.out.println(maxWeeks(projects));
    }

    private static int maxWeeks(int[] projects) {
        int max = 0;
        int sum = 0;
        for (int project : projects) {
            sum += project;
            max = Math.max(max, project);
        }
        if (sum < max) {
            return sum;
        }
        return max + (sum - max) / (max - 1);
    }
}
