import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] people = new int[n];
        int[] boats = new int[m];
        for(int i=0; i<n; i++) people[i] = sc.nextInt();
        for(int i=0; i<m; i++) boats[i] = sc.nextInt();
        
        Arrays.sort(people);
        Arrays.sort(boats);
        
        int boatsUsed = 0;
        int p = 0, b = 0;
        while(p < n && b < m) {
            if(people[p] <= boats[b]) {
                p++;
                b++;
                boatsUsed++;
            } else {
                b++;
            }
        }
        System.out.println(p == n ? boatsUsed : -1);
    }
}
