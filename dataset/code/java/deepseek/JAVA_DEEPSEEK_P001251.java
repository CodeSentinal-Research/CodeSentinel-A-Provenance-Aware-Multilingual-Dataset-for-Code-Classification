import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        int[] boxes = new int[N];
        int[] units = new int[N];
        for (int i = 0; i < N; i++) {
            boxes[i] = scanner.nextInt();
            units[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxUnits(boxes, units, T));
    }

    private static int maxUnits(int[] boxes, int[] units, int T) {
        int maxUnits = 0;
        int currentBox = 0;
        while (T > 0 && currentBox < boxes.length) {
            if (T >= boxes[currentBox]) {
                T -= boxes[currentBox];
                maxUnits += units[currentBox];
            } else {
                maxUnits += T * units[currentBox];
                T = 0;
            }
            currentBox++;
        }
        return maxUnits;
    }
}
