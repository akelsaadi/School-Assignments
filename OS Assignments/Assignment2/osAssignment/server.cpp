/*Ali Elsaadi
*Os Assignemt 2
*Cosc 3360
*/

#include "server.h"

server::server() {}
server::server(bool& debug)
{
	debug_app = debug;
}

int server::getGrade(string& name)
{
	for (int i = 0; i < size; i++)
	{
		if (sGrade[i].name == name)
		{
			grade = sGrade[i].score;
			if (debug_app)
			{
				cout << "Grade for student " << name << " was found " << endl;
				cout << "Student's Grade is: " << grade << endl;


			}
			return grade;
		}

	}
	grade = 100 - (rand() % 45 + 1);
	if (debug_app)
	{
		cout << "Student " << name << " was not found" << endl;
		cout << "Generating random grade: " << grade << endl;

	}
	return grade;
}
string server::upper(string& text) {
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}

void server::server_start()
{
	cout << "Enter the input file's name: ";
	cin >> filename;
	if (read(filename))
	{
		connections_open();
	}
	else
	{
		cout << "Could not read the file. Failed to start the server" << endl;
	}
}

void server::connections_open() {

	port = 0;
	while (port < 1024) {
		cout << "Enter the server's port number: ";
		cin >> port;
		if (port < 1024) {
			cout << "Invalid number" << endl;
		}
	}
	sockaddr_in address;
	socketServer = -1;
	memset(&address, 0, sizeof(address));

	socketServer = socket(AF_INET, SOCK_STREAM, 0);

	gethostname(host, max_host);
	hos = gethostbyname(host);

	address.sin_family = hos->h_addrtype;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(socketServer, (struct sockaddr*) &address, sizeof(address)) < 0)
	{
		cout << "Error when binding socket" << endl;
	}
	else
	{
		if (debug_app)
		{
			cout << "Socket sucessfully binded" << endl;
			cout << "# of socket: " << socketServer << endl;
		}

		if (listen(socketServer, connection_max) < 0) {
			if (debug_app) {
				cout << "Error listening for clients" << endl;
			}
		}
		else {
			cout << "Waiting for Clients. " << endl;
			while (1) {
				socketClient = -1;
				req = "";
				int addr_size = sizeof(address);
				socketClient = accept(socketServer, (sockaddr*)& address, (socklen_t*)& addr_size);
				if (socketClient < 0) {
					if (debug_app)
					{
						cout << "Failed, try again." << endl;
					}
				}
				else {
					if (debug_app) {
						cout << "Client has been accepted on socket: " << socketClient << endl;
					}
				}
				while (req != "endConn") {
					req = "";
					memset(buffer, 0, max_buff + 1);
					recv(socketClient, buffer, max_buff, 0);
					req = buffer;
					if (req != "endConn") {
						upper(req);
						if (debug_app) {
							cout << "Searching for " << req << "'s grade" << endl;
						}
						//Search in Score Table
						rep = to_string(getGrade(req));

						//Send result to Client
						send(socketClient, rep.c_str(), rep.size(), 0);
					}
				}
				if (debug_app) {
					cout << "the client socket " << socketClient << " has been close" << endl;
				}
				close(socketClient);
			}
		}

	}
	close(socketServer);
}
bool server::read(string& file)
{
	ifstream inputF(file);
	if (inputF.good()) {
		if (debug_app) {
			cout << "File available" << endl;
		}
		size = 0;
		while (!inputF.eof()) {
			inputF >> student_name;
			gradeS.name = upper(student_name);
			inputF >> gradeS.score;
			sGrade[size] = gradeS;
			size++;
		}
		inputF.close();
		if (debug_app) {
			for (int i = 0; i < size; i++) {
				cout << sGrade[i].name << " " << sGrade[i].score << endl;
			}
		}
		return true;
	}
	else {
		if (debug_app) {
			cout << "Cannot Find File" << endl;
		}
		return false;
	}
	return true;
}