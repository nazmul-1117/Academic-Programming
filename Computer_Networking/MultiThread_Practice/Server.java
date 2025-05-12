package MultiThread_Practice;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        int clientCounter = 0;
        int maxClients = 3;

        try {
            serverSocket = new ServerSocket(5000);
            System.out.println("Server started and listening on port 5000...!");

            while (clientCounter < maxClients) {
                Socket socket = serverSocket.accept();
                clientCounter++;
                System.out.println("Client " + clientCounter + " connected: " + socket.getInetAddress().getHostAddress());

                DataInputStream dis = new DataInputStream(socket.getInputStream());
                DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

                Thread newClient = new ClientHandler(dos, dis, socket);
                newClient.start();
            }

            System.out.println("Maximum number of clients reached. Server will now stop accepting new connections.");

        } catch (IOException e) {
            System.err.println("Error starting or accepting connections: " + e.getMessage());
        } finally {
            // It's important to close the ServerSocket in a finally block
            // to ensure it's closed even if an exception occurs.
            if (serverSocket != null) {
                try {
                    serverSocket.close();
                    System.out.println("Server socket closed.");
                } catch (IOException e) {
                    System.err.println("Error closing server socket: " + e.getMessage());
                }
            }
        }
    }
}