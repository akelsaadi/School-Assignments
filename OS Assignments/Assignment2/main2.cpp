 
#include <cstdlib>
#include <iostream>

#include "server.h"

using namespace std;
int main(int argc, char** argv) {

    bool debugapp=true;
    server srv(debugapp);
    srv.startServer();
    return 0;
}