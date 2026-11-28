import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String senate = scanner.next();
        System.out.println(predictPartyVictory(senate));
    }

    public static String predictPartyVictory(String senate) {
        Queue<Character> queue = new LinkedList<>();
        int[] count = new int[2];
        int[] ban = new int[2];

        for (char c : senate.toCharArray()) {
            queue.add(c);
            count[c == 'R' ? 0 : 1]++;
        }

        while (count[0] > 0 && count[1] > 0) {
            char c = queue.poll();
            if (ban[c == 'R' ? 0 : 1] > 0) {
                ban[c == 'R' ? 0 : 1]--;
                count[c == 'R' ? 0 : 1]--;
            } else {
                ban[c == 'R' ? 1 : 0]++;
                queue.add(c);
           
            }
        }

        return count[1] > 0 ? "Dire" : "Radiant";
    }
}
