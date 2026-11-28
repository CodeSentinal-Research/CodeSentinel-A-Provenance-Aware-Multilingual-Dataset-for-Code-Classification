import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        List<List<Integer>> levels = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            levels.add(new ArrayList<>());
        }

        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            if (!line.isEmpty()) {
                String[] values = line.split(" ");
                for (String value : values) {
                    int level = Integer.parseInt(value);
                    levels.get(i).add(level);
                }
           }
        }

        int minNodes = Integer.MAX_VALUE;
        int minLevel = 0;
        for (int i = 0; i < N; i++) {
            int size = levels.get(i).size();
            if (size < minNodes) {
                minNodes = size;
                minLevel = i;
            }
        }

        System.out.println(minLevel);
    }
}
