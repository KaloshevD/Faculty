import java.util.ArrayList;
import java.util.Scanner;

public class PushZero
{
    static void pushZerosToBeginning(int[] arr, int n)
    {
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                count++;
            }
        }
        int [] transformedArray = new int[n];
        for(int copier = count, counter = 0 ; counter < n; counter++){
            if(arr[counter] != 0){
                transformedArray[copier] = arr[counter];
                copier++;
            }
        }
        System.out.println("Transformiranata niza e:");
        for(int i = 0; i < n; i++){
            System.out.print(transformedArray[i] + " ");
        }
    }

    public static void main (String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        pushZerosToBeginning(arr,n);
    }
}