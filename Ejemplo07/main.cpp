#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    char c;
    bool test;
    
    cout << "Pulse teclas numéricas. Acaba pulsando ESC\n";
    
    do {
        c = getchar();
	test = ((c >= '0') && (c <= '9'));  
        
        if (test)
            cout << c << " pulsada.\n";
    } while(c != 27); 
 return 0;
} 