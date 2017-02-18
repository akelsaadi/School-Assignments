from datetime import datetime
from socket import *
from time import time

def main():
    serverName = 'localhost'
    serverHost = 12000
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    message = 'PING!    '

    counter = 10
    i = 0

    print 'Now attempting', counter, 'pings....\n'

    while i < counter:
        i+=1
        print '\nThis is ping Attempt number: ', i
        print 'There are ', counter - i , 'attempts left'

        a = datetime.now()
        clientSocket.sendto(message,(serverName, serverHost))

        clientSocket.settimeout(1)

        try:
            modifiedMessage, serverAddress = clientSocket.recvfrom(1024)

            b = datetime.now()
            c = a-b
            print modifiedMessage
            print 'elapsed time in microsseconds is', c.microseconds
        except timeout:
            print 'Sorry, Connection Timed out, try again later'

    if i == 10:
        print 'Done Bye!'

    clientSocket.close()
    print 'Socket closed'

    pass

if __name__ == '__main__':
    main()


