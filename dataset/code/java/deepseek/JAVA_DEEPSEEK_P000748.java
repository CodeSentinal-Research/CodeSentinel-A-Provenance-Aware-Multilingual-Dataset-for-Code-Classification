import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int target = scanner.nextInt();
        printAllSequences(target, "", 0);
    }

    private static void printAllSequences(int target, String sequence, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            System.out.println(sequence);
            return;
        }
        for (int i = 1; i <= 6; i++) {
            if (sequence.isEmpty()) {
                printAllSequences(target, sequence + i, sum + i);
            } else {
                printAllSequences(target, sequence + " " + i, sum + i);
           }
        }
    }
}
