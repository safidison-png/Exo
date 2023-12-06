#include <stdio.h>
#include <stdlib.h>

int main(){
    char data[255];
    scanf("%s", data);
    printf("Content-type:text/html\n\n");
    printf("<html><body>%s</body></html>", data);

    return 0;
}