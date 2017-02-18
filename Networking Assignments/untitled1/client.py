#import socket module

from socket import*
serverSocket= socket(AF_INET, SOCK_STREAM)

serverPort = 7000
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
#Fill in end
while True:
    print 'Ready to Serve'
    connectionSocket, addr = serverSocket.accept()
    try:
        message =connectionSocket.recv(1024)
        print message
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        connectionSocket.send('n\HTTP/1.x 200 OK\n\n')
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i])
        connectionSocket.close()
        print "File Received"
    except IOError:
        print "404 Not Found"
        connectionSocket.send('\n404 File Not Found\n')
        connectionSocket.close()
    serverSocket.close()
