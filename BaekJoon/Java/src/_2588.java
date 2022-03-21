import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _2588 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int A = Integer.parseInt(br.readLine());
        String B = String.valueOf(br.readLine());
        int temp1 = A * (B.charAt(2) - '0');
        int temp2 = A * (B.charAt(1) - '0');
        int temp3 = A * (B.charAt(0) - '0');

        System.out.printf("%d\n%d\n%d\n%d\n", temp1, temp2, temp3, temp1 + temp2*10 + temp3*100);

        bw.flush();
        bw.close();
    }
}
