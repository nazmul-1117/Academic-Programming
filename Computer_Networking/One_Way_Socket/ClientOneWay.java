import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientOneWay {

    public static void main(String[] args) {
        try{
            Socket soc = new Socket("localhost", 5555);
            System.err.println("Connection stablish");

            DataInputStream in = new DataInputStream(soc.getInputStream());
            DataOutputStream out = new DataOutputStream(soc.getOutputStream());

            String inputMsg = "";
            String outputMsg = "";

            while (!outputMsg.equals("TaTa")) {
                System.out.print("Enter Message: ");
                InputStreamReader input = new InputStreamReader(System.in);
                BufferedReader buffer = new BufferedReader(input);
                outputMsg = buffer.readLine();
                out.writeUTF(outputMsg);
            }

        }catch(Exception e){
            System.err.println("Error Occured " + e.getMessage());
        }
    }
}