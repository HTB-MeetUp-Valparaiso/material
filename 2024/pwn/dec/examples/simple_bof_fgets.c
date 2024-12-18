#include <stdio.h>
#include <string.h>

int main() {
    char passwd[] = "1337pass"; // hardcoded password (very secure)
    char buf[32];   // holds user input
    
    printf("Enter the password: \n");

    fgets(buf, 64, stdin);

    /* password validation */
    if (strcmp(passwd, buf) == 0) {
        printf("succesfully logged in\n");
    } else {
        printf("wrong pass!\n");
    }

    return 0;
}