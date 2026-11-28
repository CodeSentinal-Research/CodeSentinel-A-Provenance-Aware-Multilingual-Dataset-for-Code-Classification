import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int totalEdges = 0;
        for (int i = 0; i < N; i++) {
            int V = scanner.nextInt();
            int E = V - 1; // subtract 1 because each edge is counted twice
            totalEdges += E;
        }
        System.out.println(totalEdges);
    }
}
