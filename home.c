#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
void loged(char *loha, char *rdata);
char **alouer();

int main(){
    char* data = getenv("QUERY_STRING");
    char rdata[255];
    char loha[1000];
    sscanf(data, "%*[^=]=%s", rdata);
    loged(loha, rdata);
    printf("Cache-Control: no-cache, no-store, must-revalidate\n");
    printf("Pragma: no-cache\n");
    printf("Expires: 0\n");
    printf("Content-type:text/html\n\n");
    printf("<!DOCTYPE html>"
        "<html lang=\"en\">"
        "<head>"
            "<meta charset=\"UTF-8\">"
            "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
            "%s"
            "<link rel=\"stylesheet\" href=\"http://www.login.mg/style.css\">"
            "<title>Home</title>"
        "</head>"
        "<body>"
            "<nav>"
                "<div id=\"icon\">"
                    "<div class=\"icon\"></div>"
                    "<h1>%s</h1>"
                "</div>"
                "<div class=\"link\">"
                    "<a class=\"linked\" href=\"http://www.login.mg/cgi-bin/find_auth.cgi?user=%s\">Auth_log</a>"
                    "<a class=\"linked\" href=\"http://www.login.mg/cgi-bin/home.cgi?user=%s\">Access_log</a>"
                    "<a class=\"linked\" href=\"http://www.login.mg/cgi-bin/home.cgi?user=%s\">Website_status</a>"
                    "<a class=\"linked\" href=\"http://www.login.mg/cgi-bin/hosting.cgi?user=%s\">Website_hosting</a>"
                    "<a href=\"http://www.login.mg/cgi-bin/logout.cgi?user=%s\">Logout</a>"
                "</div>"
            "</nav>"
            "<div class=\"main\">"
                "<div class=\"hd\">"
                    "<p>Ce plateforme permet de faire plusieurs taches</p>"
                "</div>"
                "<div class=\"form\">"
                "</div>"
            "</div>"
        "</body>"
        "</html>", loha, rdata, rdata, rdata, rdata, rdata, rdata);
    return 0;
}

void loged(char *loha, char *rdata){
    char **b=NULL;
    char **c=NULL;
    char **d=NULL;
    char ch[255];
    char * isa = malloc(255);
    FILE* tfile;
	tfile = fopen("/home/safidison/Mit/login/db.csv", "r");
    b = alouer();
    c = alouer();
    d = alouer();
	FILE *asa = popen("cat /home/safidison/Mit/login/db.csv | wc -l", "r");
	fgets(isa, 255,  asa);
	int ab = atoi(isa);
    for(int i=0;i<ab;i++){
        fgets(ch,255,tfile);
        sscanf(ch, "%[^,],%[^,],%s", b[i], c[i], d[i]);
        if(strcmp(b[i],rdata)==0&&strcmp(d[i],"1")==0){
            strcpy(loha,"");
        }
        else if(strcmp(b[i],rdata)==0&&strcmp(d[i],"0")==0){
            strcpy(loha,"<meta http-equiv='refresh' content='2;url=http://www.login.mg/'>");
        }
    }
}

char **alouer(){
	char **a = (char**)malloc(col*sizeof(char*));
	for(int i=0;i<ta;i++){
		a[i] = malloc(ta);
	}
	return a;
}