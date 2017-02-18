/*Ali Elsaadi
*Os Assignemt 2
*Cosc 3360
*/
#ifndef Server_h
#define Server_h

#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

using namespace std;

const int connection_max = 5;
const int max_host = 200;
const int max_buff = 500;

struct ggrade {
	int score;
	string name;
};

class server {
public:
	server();
	server(bool& debug);
	void connections_open();
	void server_start();
	int getGrade(string& name);
	bool read(string& file);
	string upper(string& text);
private:
	int grade;
	int size;
	int socketServer;
	int socketClient;
	int port;
	hostent *hos;
	ggrade sGrade[1024];
	ggrade gradeS;
	char host[1024];
	char buffer[max_buff + 1];
	string filename;
	string req;
	string rep;
	string student_name;
	bool debug_app;

};
#endif // !Server_h