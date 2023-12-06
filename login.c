#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
char **alouer(char **cfile1);

int main(){
    char *data = getenv("QUERY_STRING");
    char a[2][255];
    char **b=NULL;
    char **c=NULL;
    char **d=NULL;
    b = alouer(b);
    c = alouer(c);
    d = alouer(d);
    sscanf(data, "%*[^=]=%[^&]&%*[^=]=%[^\n]\n", a[0], a[1]);
    FILE *tfile;
	tfile = fopen("/home/safidison/Mit/login/db.csv", "r");
	char * isa = malloc(255);
	FILE *asa = popen("cat /home/safidison/Mit/login/db.csv | wc -l", "r");
	fgets(isa, 255,  asa);
	int ab = atoi(isa);
    int index=-1;
    if(ab>=0){
        char ch[255];
        for(int i=0;i<ab;i++){
            fgets(ch,255,tfile);
            sscanf(ch, "%[^,],%[^,],%s", b[i], c[i], d[i]);
        }
        for(int i=0;i<ab;i++){
            if(strcmp(a[0],b[i])==0){
                index=i;
            }
        }
        if(index>=0){
            if(strcmp(a[0],b[index])==0&&strcmp(a[1],c[index])==0){
                d[index] = "1";
                FILE *tfile1;
	            tfile1 = fopen("/home/safidison/Mit/login/db.csv", "w");
                for(int i=0;i<ab;i++){
                    fprintf(tfile1, "%s,%s,%s\n", b[i], c[i], d[i]);
                }
                printf("Location: http://www.login.mg/cgi-bin/home.cgi?user=%s\n\n", a[0]);
            }
            else{
                printf("Location: http://www.login.mg/\n\n");
            }
        }
        else{
            printf("Location: http://www.login.mg/cgi-bin/sign_up.cgi\n\n");
        }
    }
    fclose(tfile);
    
    return 0;
}

char **alouer(char **cfile1){
	char **a = (char**)malloc(col*sizeof(char*));
	for(int i=0;i<ta;i++){
		a[i] = malloc(ta);
	}
	return a;
}