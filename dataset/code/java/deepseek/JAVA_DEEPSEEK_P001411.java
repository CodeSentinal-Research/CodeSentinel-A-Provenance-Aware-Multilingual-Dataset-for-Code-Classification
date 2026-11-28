import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int matches = scanner.nextInt();
        scanner.nextLine();

        Map<Integer, Integer> players = new HashMap<>();
        List<Integer> playersWithZeroLoss = new ArrayList<>();
        List<Integer> playersWithOneLoss = new ArrayList<>();

        for (int i = 0; i < matches; i++) {
            int winner = scanner.nextInt();
            int loser = scanner.nextInt();

            players.put(winner, players.getOrDefault(winner, 0) + 1);
            players.put(loser, players.getOrDefault(loser, 0) - 1);
        }

        for (Map.Entry<Integer, Integer> entry : players.entrySet()) {
            if (entry.getValue() == 0) {
                playersWithZeroLoss.add(entry.getKey());
            } else if (entry.getValue() == 1) {
                playersWithOneLoss.add(entry.getKey());
            }
        }

        Collections.sort(playersWithZeroLoss);
        Collections.sort(playersWithOneLoss);

        System.out.println(playersWithZeroLoss.size() + " " + playersWithZeroLoss);
        System.out.println(playersWithOneLoss.size() + " " + playersWithOneLoss);
    }
}
