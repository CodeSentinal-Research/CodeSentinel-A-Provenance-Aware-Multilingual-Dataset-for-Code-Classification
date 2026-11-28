import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] grid = new String[10];
        for (int i = 0; i < 10; i++) {
            if (sc.hasNextLine()) grid[i] = sc.nextLine();
            else grid[i] = "++++++++++";
        }
        for (String row : grid) System.out.println(row);
        sc.close();
    }
}