import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        boolean[] leafNodes = new boolean[n+1];
        for(int i = 1; i < n; i++) {
            String[] line = scanner.nextLine().split(" ");
            int parent = Integer.parseInt(line[0]);
            int child = Integer.parseInt(line[1]);
            if(leafNodes[child]) {
                leafNodes[child] = false;
            } else {
                leafNodes[parent] = true;
            }
       
            if(i == n-1) {
                boolean allLeafNodesHaveSiblings = true;
                for(int j = 1; j <= n; j++) {
                    if(leafNodes[j]) {
                        allLeafNodesHaveSiblings = false;
                        break;
                    }
                }
                System.out.println(allLeafNodesHaveSiblings ? "YES" : "NO");
            }
        }
    }
}
