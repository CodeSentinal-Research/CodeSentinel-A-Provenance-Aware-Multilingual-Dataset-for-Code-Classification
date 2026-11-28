import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int CarpetLength = scanner.nextInt();

        int[] tiles = new int[N];
        int[] prefixSums = new int[N + 1];

        for (int i = 0; i < N; i++) {
            tiles[i] = scanner.nextInt();
        }

        for (int i = 1; i <= N; i++) {
            prefixSums[i] = prefixSums[i - 1] + tiles[i - 1];
        }

        int maxCoveredTiles = 0;
        for (int i = 0; i < N; i++) {
            int start = Math.max(tiles[i], prefixSums[i]);
            int end = Math.min(CarpetLength, prefixSums[i + 1]);
            maxCoveredTiles = Math.max(maxCoveredTiles, end - start);
        }

        System.out.println(maxCoveredTiles);
    }
}
