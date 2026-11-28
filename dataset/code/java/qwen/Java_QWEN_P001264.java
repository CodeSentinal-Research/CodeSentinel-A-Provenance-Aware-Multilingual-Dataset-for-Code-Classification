import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] tasks = new int[n][2];
        for(int i=0; i<n; i++) {
            tasks[i][0] = sc.nextInt();
            tasks[i][1] = sc.nextInt();
        }
        
        Arrays.sort(tasks, (a, b) -> b[1] - a[1]);
        
        long energy = 0;
        for(int[] task : tasks) {
            energy = Math.max(energy, (long)task[1]);
            energy -= task[0];
        }
        System.out.println(energy);
    }
}
