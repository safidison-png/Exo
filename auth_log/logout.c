#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *tfile1;
	tfile1 = fopen("/home/safidison/Mit/login/conn.csv", "w");
    fprintf(tfile1, "%s", "none");
    printf("Location: http://www.login.mg/\n\n");

    return 0;
}