import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        boolean[] visited = new boolean[N + 1];
        System.out.println(countArrangement(N, visited));
    }

    private static int countArrangement(int N, boolean[] visited) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (i % N == 0 || N % i == 0)) {
                visited[i] = true;
                count += 1 + countArrangement(N - 1, visited);
                visited[i] = false;
            }
        }
        return count;
    }
}
