#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64

int main() {
    char c;
    char buf[BUF_SIZE];   // intermediate buffer for dealing with user input 
    char userpass[16]; // user password for comparation
    char passwd[] = "1337pass"; // hardcoded password (very secure)
    
    printf("Enter the password: ");
    
    for (char i = 0; i < BUF_SIZE; i++) {
        c = getchar();

        if (c == '\n') {
            buf[i] = '\0';
            break;
        }

        buf[i] = c; // very secure buffer write
    }

    strcpy(userpass, buf);

    /* password validation */
    if (strcmp(passwd, userpass) == 0) {
        printf("succesfully logged in\n");
    } else {
        printf("wrong pass!\n");
    }

    return 0;
}