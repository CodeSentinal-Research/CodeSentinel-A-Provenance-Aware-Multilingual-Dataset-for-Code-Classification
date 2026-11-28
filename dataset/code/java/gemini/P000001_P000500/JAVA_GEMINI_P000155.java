import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int maxCnt = 0, currCnt = 0;
            for (int i = 0; i < n; i++) {
                int val = scanner.nextInt();
                if (val == 1) {
                    currCnt++;
                    maxCnt = Math.max(maxCnt, currCnt);
                } else {
                    currCnt = 0;
                }
            }
            System.out.println(maxCnt);
        }
    }
}