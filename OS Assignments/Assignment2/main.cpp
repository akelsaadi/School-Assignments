/*Ali Elsaadi
 *Os Assignemt 2
 *Cosc 3360
 */

#include <cstdlib>
#include "client.h"

using namespace std;

int main(int argc, char** argv) {
    
    bool debugapp=true;
    client clt(debugapp);
    clt.prompt();
    return 0;
}
