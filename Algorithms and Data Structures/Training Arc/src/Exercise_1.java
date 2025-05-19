
import java.util.Scanner;
// For a given array with N integers, all the elements that are lower than the average of the whole array need to be deleted.
// For example for the array 1, 2, 3, 4, 5 the average is (1 + 2 + 3 + 4 + 5) / 5 = 15 / 5 = 3 which means that the elements 1 and 2 should be deleted,
// so the array after the transformation will be 3, 4, 5.
//
// Input: The first number in the input is the number of integers in the array N, then in the next line the elements are given, separated by spaces.
//
// Output: The array before and after the transformation.

    public class Exercise_1 {
        public static void main(String[] args) {
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();
            int[] array = new int[n];
            float avrg = 0;
            for(int i = 0; i < array.length; i++){
                array[i] = input.nextInt();
                avrg += array[i];
            }
            avrg = avrg / array.length;
            int[] newArray = new int[array.length];
            int counter = 0;
            for (int i = 0, j = 0; i < array.length; i++){
                if(array[i] >= avrg){
                    newArray[j] = array[i];
                    j++;
                    counter++;
                }
            }
            int[] printArray = new int[counter];
            for (int i = 0; i < printArray.length; i++){
                if(newArray[i] != 0){
                    printArray[i] = newArray[i];
                }
            }
            System.out.print("{");
                for (int i = 0; i < array.length; i++){
                    System.out.print(array[i]);
                    if (i != array.length - 1){
                        System.out.print(",");
                    }
                }
            System.out.print("}");

            System.out.println();

            System.out.print('{');
            for (int i = 0; i < printArray.length; i++){
                if (printArray[i] == 0) {
                   break;
                }
                else {
                    if(i != printArray.length - 1 && printArray[i+1] != 0 ){
                        System.out.print(printArray[i]);
                        System.out.print(",");
                    }
                    else {
                        System.out.print(printArray[i]);
                        break;
                    }
                }
            }
            System.out.print("}");
        }
    }
