import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class ClientHandler extends Thread{
    private DataOutputStream dos;
    private DataInputStream dis;
    private Socket socket;
    private Scanner scanner;
    private int clientNumber;

    public ClientHandler(DataOutputStream dos, DataInputStream dis, Socket socket, int clientNumber) {
        this.dos = dos;
        this.dis = dis;
        this.socket = socket;
        this.clientNumber = clientNumber;
    }

    @Override
    public void run(){
        System.out.println("Client " + clientNumber + " Connected to New Client Handler");
        while (true){
            try {
                String getMessage = dis.readUTF().toLowerCase();
                
                if(getMessage.toLowerCase().equals("ends")){
                    socket.close();
                    System.out.println("Exit from Server...");
                    break;
                }
                
                // String upperCase = getMessage.toLowerCase();
                // dos.writeUTF(upperCase);


                char operator = '\0';
                String[] number = null;

                for (int i = 0; i < getMessage.length(); i++) {
                    char ch = getMessage.charAt(i);
                    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
                        operator = ch;
                        number = getMessage.split("\\"+ch);
                        break;
                    }
                }

                double ans=-1;
                double num1 = Double.parseDouble(number[0].trim());
                double num2 = Double.parseDouble(number[1].trim());
            
                switch (operator) {
                    case '+':
                        ans = num1 + num2;
                        break;
                    case '-':
                        ans = num1 - num2;
                        break;
                    case '*':
                        ans = num1 * num2;
                        break;
                    case '/':
                        if (num2 != 0) {
                            ans = num1 / num2;
                        } else {
                            System.out.println("Error: Division by zero");
                        }
                        break;
                    case '%':
                        if (num2 != 0) {
                            ans = num1 % num2;
                        } else {
                            System.out.println("Error: Modulo by zero");
                        }
                        break;
                    default:
                        System.out.println("Unsupported operator.");
                }

                System.out.println("Ans: "+ ans);
                dos.writeUTF(ans+"0");

            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }

        try {
            dos.close();
            dis.close();
            socket.close();
            scanner.close();

        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}