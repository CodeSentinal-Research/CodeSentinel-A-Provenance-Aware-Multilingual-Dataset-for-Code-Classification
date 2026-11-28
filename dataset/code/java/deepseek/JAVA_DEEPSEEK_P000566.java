import java.util.*;

public class Main {
    public static void main(String[] args) {
        String start = "AACCGGTT";
        String end = "AAACGGTA";
        String[] bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        System.out.println(minMutation(start, end, bank));
    }

    public static int minMutation(String start, String end, String[] bank) {
        if (start.equals(end)) {
            return 0;
        }

        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(end)) {
            return -1;
        }

        char[] charSet = new char[]{'A', 'C', 'G', 'T'};

        Queue<String> queue = new LinkedList<>();
        queue.offer(start);

        Set<String> visited = new HashSet<>();
        visited.add(start);

        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                char[] current = queue.poll().toCharArray();
                for (int j = 0; j < current.length; j++) {
                    char temp = current[j];
                    for (char c : charSet) {
                        current[j] = c;
                        String next = new String(current);
                        if (next.equals(end)) {
                            return steps + 1;
                        }
                        if (bankSet.contains(next) && !visited.contains(next)) {
                            queue.offer(next);
                            visited.add(next);
                        }
                    }
                    current[j] = temp;
                }
            }
            steps++;
        }

        return -1;
    }
}
