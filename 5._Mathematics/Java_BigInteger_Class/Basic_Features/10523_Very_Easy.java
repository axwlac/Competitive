import java.util.Scanner;
import java.math.BigInteger;

class Very_Easy {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while (scanner.hasNextInt()){
            BigInteger sum = BigInteger.ZERO;
            int n = scanner.nextInt();
            BigInteger a = scanner.nextBigInteger();
            for(int i=1; i<n+1; i++){
                sum = sum.add( BigInteger.valueOf(i).multiply(a.pow(i)));
            }
            System.out.println(sum);
        }
    }

}