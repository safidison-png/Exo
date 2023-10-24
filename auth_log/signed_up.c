#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
char **alouer(char **cfile1);

int main(){
    char *data = getenv("QUERY_STRING");
    char a[3][255];
    char **b=NULL;
    char **c=NULL;
    char *isa;
    int ab;
    int index=-1;
    char ch[255];
    FILE *tfile;
    b = alouer(b);
    c = alouer(c);
    sscanf(data, "%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]\n", a[0], a[1], a[2]);
	tfile = fopen("/home/safidison/Mit/login/db.csv", "a+");
    isa = malloc(255);
	FILE *asa = popen("cat /home/safidison/Mit/login/db.csv | wc -l", "r");
	fgets(isa, 255,  asa);
	ab = atoi(isa);
    printf("Content-type:text/html\n\n");
    printf("<html><head> <style>body{height: 98vh;width: 99vw;background: linear-gradient(20deg, #000, #151516, #333b35, #000);display: flex;justify-content: center;align-items: center;}.main{display: flex;}.main .hd{width: 30vw;color: #fff;margin-right: 5vw;font-family: cursive;font-size: 1.5vw;}.main .form{width: 50vw;height: 20vw;border-radius: .2vw;display: flex;justify-content: center;align-items: center;flex-direction: column;font-size: 1vw;text-align: center;}.main .form a{text-decoration: none;color: #fff;font-weight: bold;font-family: sans-serif;width: 5vw;height: 1.5vw;background: linear-gradient(3deg, #000, #460833, #f00, #f00, #f00);border-radius: 5vw;padding: .5vw;}.main .form p{font-family: serif;font-weight: bold;font-size: 1.5vw;}</style></head><body>");
    for(int i=0;i<=ab;i++){
        fgets(ch,255,tfile);
        sscanf(ch, "%[^,],%s", b[i], c[i]);
    }
    for(int i=0;i<=ab;i++){
        if(strcmp(a[0],b[i])==0){
            index=i;
        }
    }
    printf("<div class=\"main\">"
            "<div class=\"hd\">"
                "<h1>Signup for free</h1>"
                "<p>Signup to join 20 000 persons for discovering another somethings</p>"
            "</div>");
    if(index<0){
        if(strcmp(a[1], a[2])==0){
            fprintf(tfile, "\n%s,%s", a[0], a[1]);
            printf("<div class=\"form\"><p>Register successfuly</p><a  href=\"http://www.login.mg/\">OK</a></div>");
        }
        else{
            printf("<div class=\"form\"><p style=\"color:#f00;text-align:center;\">Password incorrect</p><a href=\"http://www.login.mg/cgi-bin/sign_up.cgi\">OK</a></div>");
        }
    }
    else{
        printf("<div class=\"form\"><p style=\"color:#f00;text-align:center;\">Username already exist</p><a href=\"http://www.login.mg/cgi-bin/sign_up.cgi\">OK</a></div>");
    }
    printf("</div></body></html>");
    

    return 0;
}

char **alouer(char **cfile1){
	char **a = (char**)malloc(col*sizeof(char*));
	for(int i=0;i<ta;i++){
		a[i] = malloc(ta);
	}
	return a;
}