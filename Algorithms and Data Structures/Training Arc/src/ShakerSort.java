import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ShakerSort {

    static void print(int a[], int n){
        for(int i=0; i<n; i++){
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }

    static void shakerSort(int a[], int n)
        // Vasiot kod tuka
    {
        boolean flag = true;
        int start = 0;
        int end = n-1;
        while (flag){
            print(a, n);
            flag=false;
            for(int i=start; i<end-1; i++){
                if(a[i]>a[i+1]){
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    flag=true;
                }
            }
            if (!flag){
                break;
            }
            end = end-1;
            print(a, n);
            for (int i=end-1; i>=start; i--){
                if(a[i]>a[i+1]){
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    flag=true;
                }
            }
            start = start+1;
            print(a, n);
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
        shakerSort(a,n);
    }
}