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
            "<title>Web hosting</title>"
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
                    "<p>Ce plateforme permet de chercher les informations d'authentification correspondantes avec l'utilisateur</p>"
                "</div>"
                "<form action=\"http://www.login.mg/hosted.cgi\" method=\"post\">"
                    "<label for=\"serverN\">Server name</label>"
                    "<input type=\"text\" name=\"serverN\" placeholder=\"www.example-conf.mg\" class=\"in\">"
                    "<label for=\"serverA\" class=\"form-label\">Server admin</label>"
                    "<input type=\"text\" name=\"serverA\" placeholder=\"webmaster@localhost\" class=\"in\">"
                    "<label for=\"docRoot\" class=\"form-label\">Document root</label>"
                    "<input type=\"text\" name=\"docRoot\" placeholder=\"/home/user/site/example/\" class=\"in\">"
                    "<div class=\"check\">"
                        "<input name=\"inde1\" class=\"form-check-input\" type=\"checkbox\"><label>Indexes</label>"
                        "<input name=\"inde2\" class=\"form-check-input\" type=\"checkbox\"><label>Error</label>"
                        "<input name=\"inde3\" class=\"form-check-input\" type=\"checkbox\"><label>Access</label>"
                    "</div>"
                    "<input type=\"text\" value=\"%s\" name=\"user\" style=\"display: none;\">"
                    "<input class=\"in fbtn\" type=\"submit\" value=\"Host\">"
                "</form>"
            "</div>"
        "</body>"
        "</html>", loha, rdata, rdata, rdata, rdata, rdata, rdata, rdata);
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