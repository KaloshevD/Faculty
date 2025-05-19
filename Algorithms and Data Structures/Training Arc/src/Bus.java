import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bus {

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        br.close();

        // Vasiot kod tuka
        int ticket_price = 100;
        int min;
        int max;

        if(M < N){
            min = N * ticket_price;
        }
        else {
            min = (N*ticket_price) + ((M-N) *ticket_price);
        }
        if(M == 0) {
            max = (N * ticket_price);
        }
        else {
            max = (N * ticket_price) + (M * ticket_price) - 100;
        }


        System.out.println(min);
        System.out.println(max);
    }

}
