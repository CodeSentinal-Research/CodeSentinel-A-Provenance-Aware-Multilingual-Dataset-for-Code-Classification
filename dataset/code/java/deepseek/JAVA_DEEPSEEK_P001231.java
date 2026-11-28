import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] childrenRequirements = new int[N];
        for (int i = 0; i < N; i++) {
            childrenRequirements[i] = scanner.nextInt();
        }
        int M = scanner.nextInt();
        int[] cookieSizes = new int[M];
        for (int i = 0; i < M; i++) {
            cookieSizes[i] = scanner.nextInt();
        }
        Arrays.sort(childrenRequirements);
        Arrays.sort(cookieSizes);
        int satisfiedChildren = 0;
        int i = 0;
        int j = M - 1;
        while (i < N && j >= 0) {
            if (childrenRequirements[i] <= cookieSizes[j]) {
                satisfiedChildren++;
                i++;
            }
            j--;
        }
        System.out.println(satisfiedChildren);
    }
}
