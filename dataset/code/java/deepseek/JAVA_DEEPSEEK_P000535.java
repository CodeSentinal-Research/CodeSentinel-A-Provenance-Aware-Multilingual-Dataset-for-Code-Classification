import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] deck = {17,25,19,21,16,22,18,11};
        int[] result = deckRevealedIncreasing(deck);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }

    public static int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.add(i);
        }
        Arrays.sort(deck);
        int[] res = new int[n];
        for (int card : deck) {
            res[queue.poll()] = card;
            if (!queue.isEmpty()) {
                queue.add(queue.poll());
            }
       }
        return res;
    }
}
