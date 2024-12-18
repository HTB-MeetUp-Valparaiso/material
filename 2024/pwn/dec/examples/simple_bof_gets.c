#include <stdio.h>
#include <string.h>

int main() {
    char buf[32];   // holds user input
    char passwd[] = "1337pass"; // hardcoded password (very secure)
    
    printf("Enter the password: \n");
    gets(buf);

    /* password validation */
    if (strcmp(passwd, buf) == 0) {
        printf("succesfully logged in\n");
    } else {
        printf("wrong pass!\n");
    }

    return 0;
}