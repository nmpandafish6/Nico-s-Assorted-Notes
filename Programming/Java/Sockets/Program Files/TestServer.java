import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServer {

    public static void main(String[] args) throws IOException {
        //Creates a server on port 9000 on the local computer
        ServerSocket m_server = new ServerSocket(9000);
        //Waits for a device to connect to the server
        Socket m_client = m_server.accept();
        //Creates an output stream for sending information to a client
        PrintWriter m_dataOut = new PrintWriter(m_client.getOutputStream(), true);
        //Creates an input stream for reading information from a client
        BufferedReader m_dataIn = new BufferedReader(new InputStreamReader(m_client.getInputStream()));
        
        //Sends a message to the client
        m_dataOut.println("New Message From Server");
        //Reads an incoming message from the client and prints the message
        String incomingMessage = m_dataIn.readLine();
        System.out.println(incomingMessage);
    }
    
}

