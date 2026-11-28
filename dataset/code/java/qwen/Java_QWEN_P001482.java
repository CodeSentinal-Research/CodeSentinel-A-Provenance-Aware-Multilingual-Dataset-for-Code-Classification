import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int power = sc.nextInt();
        int[] tokens = new int[n];
        for(int i=0; i<n; i++) tokens[i] = sc.nextInt();
        
        Arrays.sort(tokens);
        int score = 0, maxScore = 0;
        int left = 0, right = n - 1;
        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                maxScore = Math.max(maxScore, score);
            } else if(score > 0) {
                power += tokens[right--];
                score--;
            } else {
                break;
            }
        }
        System.out.println(maxScore);
    }
}
