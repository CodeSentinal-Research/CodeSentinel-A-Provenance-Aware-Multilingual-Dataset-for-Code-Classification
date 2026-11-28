import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine();

        Set<Integer>[] rowSets = new HashSet[rows];
        for (int i = 0; i < rows; i++) {
            rowSets[i] = new HashSet<>();
            String[] numbers = scanner.nextLine().split(" ");
            for (String number : numbers) {
                rowSets[i].add(Integer.parseInt(number));
            }
       }

        Set<Integer> common = new HashSet<>(rowSets[0]);
        for (int i = 1; i < rows; i++) {
            common.retainAll(rowSets[i]);
        }

        for (Integer num : common) {
            System.out.println(num);
        }
    }
}
