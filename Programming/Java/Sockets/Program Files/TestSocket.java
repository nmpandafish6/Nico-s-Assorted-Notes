import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class TestSocket {
    
    public static void main(String[] args) throws IOException {
        //Connects to a server at the following IP Address and port
        Socket m_client = new Socket("127.0.0.1", 9000);
        PrintWriter m_dataOut = new PrintWriter(m_client.getOutputStream(), true);
        //Creates an input stream for reading information from a client
        BufferedReader m_dataIn = new BufferedReader(new InputStreamReader(m_client.getInputStream()));
        
        //Sends a message to the server
        m_dataOut.println("New Message From " + m_client.getLocalAddress());
        //Reads an incoming message from the server and prints the message
        String incomingMessage = m_dataIn.readLine();
        System.out.println(incomingMessage);
    }
    
}

