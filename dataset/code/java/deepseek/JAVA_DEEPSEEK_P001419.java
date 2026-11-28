import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(sortCharactersByOccurrence(input));
    }

    public static String sortCharactersByOccurrence(String s) {
        Map<Character, Integer> charCountMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Character> pq = new PriorityQueue<>(
                (a, b) -> {
                    int countA = charCountMap.get(a);
                    int countB = charCountMap.get(b);
                    return countB - countA;
                }
        );

        for (char c : charCountMap.keySet()) {
            pq.offer(c);
        }

        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            char c = pq.poll();
            for (int i = 0; i < charCountMap.get(c); i++) {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}
