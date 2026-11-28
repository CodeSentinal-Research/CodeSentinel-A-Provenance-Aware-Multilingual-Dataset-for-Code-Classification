import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(frequencySort(input));
    }

    public static String frequencySort(String s) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Character> queue = new PriorityQueue<>(
                (a, b) -> {
                    int frequencyA = frequencyMap.get(a);
                    int frequencyB = frequencyMap.get(b);
                    if (frequencyA != frequencyB) {
                        return frequencyA - frequencyB;
                    } else {
                        return b - a;
                    }
                }
        );

        for (char c : frequencyMap.keySet()) {
            queue.offer(c);
        }

        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            char c = queue.poll();
            for (int i = 0; i < frequencyMap.get(c); i++) {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}
