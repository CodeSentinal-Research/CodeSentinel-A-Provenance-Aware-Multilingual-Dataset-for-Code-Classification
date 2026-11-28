import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] counts = new int[N];
        for (int i = 0; i < N; i++) {
            counts[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            if (scanner.next().equals("L")) {
                counts[i] = 1;
            }
       
            int left = i;
            while (left != 0) {
                left = (left - 1) / 2;
                counts[left] += counts[i];
            }
        }
        int maxCount = 0;
        int maxLevel = 0;
        for (int i = 0; i < N; i++) {
            if (counts[i] > maxCount) {
                maxCount = counts[i];
                maxLevel = i;
            }
        }
        System.out.println(maxLevel);
    }
}
