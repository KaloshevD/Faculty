import java.util.Scanner;

class QuarterlySales {

    private int numOfSales;
    private int [] revenues;
    private int quarterNo;

    public QuarterlySales(int numOfSales, int[] revenues, int quarterNo) {
        this.numOfSales = numOfSales;
        this.revenues = revenues;
        this.quarterNo = quarterNo;
    }

    public int getTotalRevenue(){
        int totalRevenues = 0;
        for (int i = 0; i < revenues.length; i++) {
            totalRevenues += revenues[i];
        }
        return totalRevenues;
    }

    @Override
    public String toString() {
        return String.valueOf(getTotalRevenue());
    }

}

class SalesPerson {

    private String name;
    private QuarterlySales [] quarters;

    public SalesPerson(String name, QuarterlySales[] quarters) {
        this.name = name;
        this.quarters = quarters;
    }

    public String getName() {
        return name;
    }

    public int getTotalRevenue() {
        int total = 0;
        for (QuarterlySales qs : quarters) {
            total += qs.getTotalRevenue();
        }
        return total;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(name).append("   ");
        int grandTotal = 0;
        for (QuarterlySales qs : quarters) {
            int quarterlyTotal = qs.getTotalRevenue();
            sb.append(quarterlyTotal).append("   ");
            grandTotal += quarterlyTotal;
        }
        sb.append(grandTotal);
        return sb.toString();
    }

}


public class Main {

    public static int sumSales(SalesPerson sp) {
        return sp.getTotalRevenue();
    }

    public static SalesPerson salesChampion(SalesPerson[] arr) {
        SalesPerson champion = arr[0];
        for (SalesPerson sp : arr) {
            if (sp.getTotalRevenue() > champion.getTotalRevenue()) {
                champion = sp;
            }
        }
        return champion;
    }

    public static void table(SalesPerson[] arr) {
        System.out.println("SP   1   2   3   4   Total");
        for (SalesPerson sp : arr) {
            System.out.println(sp);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        SalesPerson[] arr = new SalesPerson[n];

        for (int i = 0; i < n; i++) {
            String name = input.next();
            QuarterlySales[] quarters = new QuarterlySales[4];

            for (int j = 0; j < 4; j++) {
                int numOfSales = input.nextInt();
                int[] revenues = new int[numOfSales];
                for (int k = 0; k < numOfSales; k++) {
                    revenues[k] = input.nextInt();
                }
                quarters[j] = new QuarterlySales(numOfSales, revenues, j + 1);
            }
            arr[i] = new SalesPerson(name, quarters);
        }

        table(arr);
        System.out.println();
        System.out.println("SALES CHAMPION: " + salesChampion(arr).getName());
    }
}