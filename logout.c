#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
char **alouer();

int main(){
    char *data = getenv("QUERY_STRING");
    char rdata[255];
    char **b=NULL;
    char **c=NULL;
    char **d=NULL;
    b = alouer();
    c = alouer();
    d = alouer();
    FILE *tfile;
	tfile = fopen("/home/safidison/Mit/login/db.csv", "r");
	char * isa = malloc(255);
	FILE *asa = popen("cat /home/safidison/Mit/login/db.csv | wc -l", "r");
	fgets(isa, 255,  asa);
	int ab = atoi(isa);
    char ch[255];
    sscanf(data, "%*[^=]=%s", rdata);
    for(int i=0;i<ab;i++){
        fgets(ch,255,tfile);
        sscanf(ch, "%[^,],%[^,],%s", b[i], c[i], d[i]);
    }
    for(int i=0;i<ab;i++){
        if(strcmp(rdata,b[i])==0){
            strcpy(d[i],"0");
        }
    }
    FILE *tfile1;
    tfile1 = fopen("/home/safidison/Mit/login/db.csv", "w");
    for(int i=0;i<ab;i++){
        fprintf(tfile1, "%s,%s,%s\n", b[i], c[i], d[i]);
    }
    printf("Location: http://www.login.mg/\n\n");
    fclose(tfile);

    // printf("Content-type:text/html\n\n");
    // printf("<html><body>Success =>%s</body></html>", rdata);

    return 0;
}

char **alouer(){
	char **a = (char**)malloc(col*sizeof(char*));
	for(int i=0;i<ta;i++){
		a[i] = malloc(ta);
	}
	return a;
}