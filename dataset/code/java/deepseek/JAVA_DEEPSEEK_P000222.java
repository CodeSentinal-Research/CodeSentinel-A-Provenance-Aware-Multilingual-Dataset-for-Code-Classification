import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[] arr = new int[n];
        int[] dep = new int[n];
        String[] str1 = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(str1[i]);
            dep[i] = Integer.parseInt(str2[i]);
        }
        System.out.println(findPlatforms(arr, dep, n));
    }

    static int findPlatforms(int arr[], int dep[], int n) {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int platformsNeeded = 1;
        int maxPlatforms = 1;
        int i = 1;
        int j = 0;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platformsNeeded++;
                i++;
                if (platformsNeeded > maxPlatforms) {
                    maxPlatforms = platformsNeeded;
                }
            } else {
                platformsNeeded--;
                j++;
            }
        }
        return maxPlatforms;
    }
}
