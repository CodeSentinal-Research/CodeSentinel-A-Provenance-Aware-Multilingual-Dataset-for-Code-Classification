import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String dna = scanner.nextLine();
        Set<String> sequences = new HashSet<>();
        Map<String, Integer> countMap = new HashMap<>();

        for (int i = 0; i < dna.length() - 9; i++) {
            String sequence = dna.substring(i, i + 10);
            countMap.put(sequence, countMap.getOrDefault(sequence, 0) + 1);
        }

        for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() > 1) {
                System.out.println(entry.getKey());
            }
        }
    }
}
