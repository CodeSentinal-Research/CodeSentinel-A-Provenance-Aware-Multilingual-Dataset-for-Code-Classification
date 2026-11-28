import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] cars = new int[n][2];
        for(int i=0; i<n; i++) {
            cars[i][0] = sc.nextInt();
            cars[i][1] = sc.nextInt();
        }
        
        double[] res = new double[n];
        Arrays.fill(res, -1.0);
        Stack<int[]> stack = new Stack<>();
        for(int i=n-1; i>=0; i--) {
            while(!stack.isEmpty()) {
                int[] top = stack.peek();
                if(cars[i][1] <= cars[top[0]][1]) {
                    stack.pop();
                    continue;
                }
                double time = (double)(cars[top[0]][0] - cars[i][0]) / (cars[i][1] - cars[top[0]][1]);
                if(res[top[0]] < 0 || time <= res[top[0]]) {
                    res[i] = time;
                    break;
                } else {
                    stack.pop();
                }
            }
            stack.push(new int[]{i, cars[i][1]}); // storing index and speed
        }
        // Note: Logic simplified for Car Fleet II, exact implementation requires careful handling of collision times
        for(double d : res) System.out.printf("%.6f ", d);
    }
}
