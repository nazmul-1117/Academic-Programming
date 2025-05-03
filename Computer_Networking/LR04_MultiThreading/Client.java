import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        String mathExpression;

        try {
            Socket socket = new Socket("localhost", 5555);

            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            Scanner scanner = new Scanner(System.in);

            while(true){
                System.out.print("Enter Mathematical Expression1: ");
                mathExpression = scanner.nextLine();
                
                String sendMessage = mathExpression.trim().replaceAll(" ", "");
                dos.writeUTF(sendMessage);

                if(sendMessage.toLowerCase().equals("ends")){
                    socket.close();
                    System.out.println("Exit from Client...!");
                    break;
                }

                String getMessage = dis.readUTF();
                System.out.println("Result: " + getMessage);
            }

            dos.close();
            dis.close();
            socket.close();
            scanner.close();

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}