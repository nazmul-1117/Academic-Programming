package MultiThread_Practice;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientHandler extends Thread {

    private DataOutputStream dos;
    private DataInputStream dis;
    private Socket socket;

    ClientHandler(DataOutputStream dos, DataInputStream dis, Socket socket) {
        this.dis = dis;
        this.dos = dos;
        this.socket = socket;
    }

    @Override
    public void run() {
        System.out.println("Client connected. Ready to receive messages...");
        try {
            while (true) {
                String inputMsg = dis.readUTF().toLowerCase();

                if (inputMsg.equals("bye")) {
                    System.out.println("Client " + socket.getInetAddress().getHostAddress() + " requested to exit.");
                    break; // Exit the loop and the run() method, terminating the thread
                }

                String outputMsg = inputMsg.toUpperCase();
                dos.writeUTF(outputMsg);
                dos.flush(); // Ensure the message is sent immediately
            }
        } catch (IOException e) {
            System.err.println("IO Exception occurred for client " + socket.getInetAddress().getHostAddress() + ": " + e.getMessage());
        } finally {
            // Close resources in a finally block to ensure they are always closed
            try {
                if (dos != null) dos.close();
                if (dis != null) dis.close();
                if (socket != null) {
                    System.out.println("Connection with client " + socket.getInetAddress().getHostAddress() + " closed.");
                    socket.close();
                }
            } catch (IOException e) {
                System.err.println("Error closing resources for client " + socket.getInetAddress().getHostAddress() + ": " + e.getMessage());
            }
        }
        System.out.println("ClientHandler thread for " + socket.getInetAddress().getHostAddress() + " finished.");
    }
}