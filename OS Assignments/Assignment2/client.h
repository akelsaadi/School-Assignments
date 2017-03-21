    /*Ali Elsaadi
     *Os Assignemt 2
     *Cosc 3360
     */

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <algorithm>

using namespace std;

const int MAXBUFF = 500;
const int MAXHOSTNAME=200;

class client {
public:
    client();
    client(bool& debug);
    void requestGrade();
    void printResult(string& name, string& score);
    void prompt();
    string toUpper(string& text);
private:
    int port;
    char hostname[1024];
    bool appDebug;
    int client_socket;
    char buffer[MAXBUFF + 1];
    string request;
    string reply;
    bool stop;

};

#endif /* CLIENT_H */