import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5555);
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            Scanner scanner = new Scanner(System.in);

            while (true) {
               String inLine =  dis.readUTF();
               System.err.println(inLine);

               String outLine = scanner.nextLine();
               dos.writeUTF(outLine);

               if(outLine.equals("bye")){
                System.err.println("Exiting from Client...");
                socket.close();
                break;
               }
            }

            dos.close();
            dis.close();
            socket.close();

        } catch (Exception e) {
            // TODO: handle exception
            System.err.println("DD");
        }
    }
    
}
