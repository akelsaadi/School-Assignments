/*Ali Elsaadi
 *Os Assignemt 2
 *Cosc 3360
 */

#include "client.h"

client::client() {
}

client::client(bool& debug) {

    appDebug = debug;
}

void client::requestGrade() {

    //Initialize
    client_socket = -1;
    sockaddr_in address;
    memset(&address, 0, sizeof (address));
    stop = false;

    while (!stop) {

        request = "";
        //Create Socket
        client_socket = (AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        inet_pton(AF_INET, hostname, &address.sin_addr);
        cin.ignore(100, '\n');
        cout << "Enter a student nickname or Press ENTER to Exit: ";
        getline(cin, request);
        if (request.empty()) {
            cout << "ENTER was pressed. Closing Client..." << endl;
            break;
        } else {
            //Connect
            if (connect(client_socket, (sockaddr*) & address, sizeof (address)) < 0) {
                cout << "Failed to connect to Server " << hostname << endl;
                stop = true;
            } else {
                if (appDebug) {
                    cout << "Successfully connected to Server " << hostname << endl;
                }

                //Send Request
                send(client_socket, request.c_str(), request.size(), 0);

                //Reset Buffer
                memset(buffer, 0, MAXBUFF + 1);

                //Receive Result
                recv(client_socket, buffer, MAXBUFF, 0);
                reply = buffer;

                printResult(request, reply);

                //Disconnect
                request = "endConn";
                send(client_socket, request.c_str(), request.size(), 0);

                //Closing Socket
                close(client_socket);

            }
        }
    }

}

void client::printResult(string& name, string& score) {

    cout << "Student " << name << " got " << score << " on the quiz\n";
    cout << "Press ENTER to Continue....";

}

void client::prompt() {

    //Get local hostname using gethostname()
    gethostname(hostname, MAXHOSTNAME);
    string localHost = hostname;
    toUpper(localHost);
    int counter = 0;
    cout << "Local Hostname: " << localHost << endl;
    string input = "";
    while (input != localHost) {
        cout << "Enter a server host name: ";
        cin>>input;
        toUpper(input);
        counter++;
        if (counter == 3) {
            cout << "Maximum Attempts reached. Exiting Application...\n";
            return;
        }
    }

    port = 0;
    while (port < 1024) {
        cout << "Enter server port number: ";
        cin>>port;
        if (port < 1024) {
            cout << "Invalid Port Number. Must be > 1024" << endl;
        }
    }
    requestGrade();
}

string client::toUpper(string& text) {
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    return text;
}