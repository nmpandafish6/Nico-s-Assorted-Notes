#Sockets

##Overview
Sockets are an easy way to connect multiple devices on a network.
Sockets work via TCP/IP networks.
Sockets require one computer to be the master (Server).
Other devices on the network can be referred to as clients.

##Good Practice
ServerSocket::accept() is a blocking function. If your code shouldn't start until you have a connection, place the accept() function in the the main program logic. If your code should run regardless of a connection, place the accept() function in a separate thread.

When testing code, it is often best to test the code on the local device before testing the code between multiple devices. To do this set the target ip address to "127.0.0.1"

When deciding on which port your socket use, pick a port that isn't already commonly used. Port 80 and 8080 are most often used for HTTP.
Port 21 and 22 are commonly used for SSH and FTP. A handy list can be found here (http://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers)

It is also a good idea to close sockets when you are done with them by using Socket::close()

It is best practice use some kind of delimiter when sending messages over socket.

##Troubleshooting

If your socket connection does not work...
	Check that the ports of the server and client match.
	Check that the IP Address of the client matches that of the server.
	Try using a different port.
	Check that any output stream flushes that data after data is written.
	Check that the appropriate delimiters exist for the input stream reader.

##Fun Facts

You can connect to your socket via HTTP. Just go to the following address IPADDRESS:PORT

You can also a more secure type of socket called an SSLSocket.
