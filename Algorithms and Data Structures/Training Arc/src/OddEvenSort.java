import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class OddEvenSort {

    static void oddEvenSort(int a[], int n)
    {
        // Vasiot kod tuka
        int[] numOdd = new int[n];
        int[] numEven = new int[n];
        Arrays.sort(a);
        int count = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] % 2 != 0) {
                numOdd[i] = a[i];
            }
        }

        for (int i = 0; i < n; i++){
            if (a[i] % 2 == 0) {
                numEven[i] = a[i];
            }
        }

        for (int i = 0, j = 0; i < n; ++i){
            if (numOdd[i] % 2 != 0){
                a[j] = numOdd[i];
                count++;
                j++;
            }
        }

        for (int i = n-1; i + n != n-1; i--){
            if (numEven[i] % 2 == 0 && numEven[i] != 0){
                a[count] = numEven[i];
                count++;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        int i;
        BufferedReader stdin = new BufferedReader( new InputStreamReader(System.in));
        String s = stdin.readLine();
        int n = Integer.parseInt(s);

        s = stdin.readLine();
        String [] pom = s.split(" ");
        int [] a = new int[n];
        for(i=0;i<n;i++)
            a[i]=Integer.parseInt(pom[i]);
        oddEvenSort(a,n);
        for(i=0;i<n-1;i++)
            System.out.print(a[i]+" ");
        System.out.print(a[i]);
    }
}