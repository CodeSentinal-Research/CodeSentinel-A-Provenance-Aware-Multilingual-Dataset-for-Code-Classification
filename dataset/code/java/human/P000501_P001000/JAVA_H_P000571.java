import java.util.Queue;
import java.util.LinkedList;

/**
 * Application: Hot Potato Game Simulation
 */
class HotPotato {
    
    /**
     * Find the winner of hot potato game
     * @param players list of player names
     * @param passes number of passes before elimination
     * @return the name of the winner
     */
    public static String findWinner(String[] players, int passes) {
        Queue<String> queue = new LinkedList<>();
        
        // TODO: Complete this method
        // 1. Add all players to the queue
        for (int i = 0; i < passes; i++) {
            queue.add(players[0]);
        }

        // 2. While more than 1 player remains:
        while (queue.size() > 1) {
            // Pass the potato 'passes' times (remove & add back)
            for (int i = 0; i < passes; i++) {
                String currentPlayer = queue.remove();
                queue.add(currentPlayer);
            }

            // Eliminate current player (remove without adding back)
            queue.remove();
        }

        // 3. Return the last remaining player
        return queue.peek();


        // Algorithm Hints:
        // - Use queue.add() to add all players initially
        // - For passing: use queue.add(queue.remove()) to move front to back
        // - For elimination: just use queue.remove() without adding back
        // - Continue until queue.size() == 1
        
    }
    
    /**
     * Main method for testing
     */
    public static void main(String[] args) {
        // Test case 1
        String[] players1 = {"Alice", "Bob", "Charlie", "David", "Eve"};
        System.out.println("Game 1: 7 passes");
        String winner1 = findWinner(players1, 7);
        System.out.println("Winner: " + winner1);
        System.out.println();
        
        // Test case 2
        String[] players2 = {"Tom", "Jerry", "Spike", "Tyke"};
        System.out.println("Game 2: 3 passes");
        String winner2 = findWinner(players2, 3);
        System.out.println("Winner: " + winner2);
        System.out.println();
        
        // Test case 3
        String[] players3 = {"A", "B", "C", "D", "E", "F"};
        System.out.println("Game 3: 5 passes");
        String winner3 = findWinner(players3, 5);
        System.out.println("Winner: " + winner3);
    }
}
