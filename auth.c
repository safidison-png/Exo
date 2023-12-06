#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
void loged(char *loha, char *rdata);
char **alouer();
char* joursSemaine(double year, double mounth, double day);
void write(FILE *tfile, char *ch1, char* data, int ab, char **b, char **c, char **a, char **session, char **date, char **status, char **user);

int main(){
    char* data = getenv("QUERY_STRING");
	FILE *tfile;
	tfile = fopen("/var/log/auth.log", "r");
	char * isa = malloc(255);
	FILE *asa = popen("cat /var/log/auth.log | wc -l", "r");
	fgets(isa, 255,  asa);
	int ab = atoi(isa);
	char** user = NULL, **session = NULL, **date = NULL, **status = NULL, **a = NULL, **b = NULL, **c = NULL;
    char ch1[255];
    char loha[1000];
	sscanf(data, "%*[^=]=%*[^&]&%*[^=]=%*[^&]&%*[^=]=%[^\n]\n", ch1);
	loged(loha, ch1);
    // (strcmp(ch1,"none")==0)?strcpy(loha,"<meta http-equiv='refresh' content='2;url=http://www.login.mg/'>"):strcpy(loha,"");
	a = alouer();
	b = alouer();
	c = alouer();
	user = alouer();
	date = alouer();
	session = alouer();
	status = alouer();
	printf("Cache-Control: no-cache, no-store, must-revalidate\n");
    printf("Pragma: no-cache\n");
    printf("Expires: 0\n");
    printf("Content-type:text/html\n\n");
	printf("<html><head>%s <link rel=\"stylesheet\" href=\"http://www.login.mg/style.css\"><title>Results</title></head><body>", loha);
	write(tfile, ch1, data, ab, b, c, a, session, date, status, user);
	printf("</body></html>");
	// fclose(tfile);
	// fclose(tfile1);
		
	return 0;
}

void write(FILE *tfile, char *ch1, char* data, int ab, char **b, char **c, char **a, char **session, char **date, char **status, char **user){
	char rdata[255];
	int page = 1, line=0;
	char *io = malloc(50);
	char isa1[255];
	int j=0;
	char **user1 = NULL, **session1 = NULL, **date1 = NULL, **status1 = NULL;
	user1 = alouer();
	date1 = alouer();
	session1 = alouer();
	status1 = alouer();
	sscanf(data, "%*[^=]=%[^&]&%*[^=]=%d%*[^\n]\n", rdata, &page);
	printf("<nav>"
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
            "</nav>", ch1, ch1, ch1, ch1, ch1, ch1);
	printf("<div class=\"main\">");
	printf("<div class=\"hd\"><p>Les resultats du recherche des journales d'authentifications de l'utilisateur %s</p></div><div class=\"aty\">", rdata);
	for(int i=0;i<ab;i++){
		char ch[255];
		fgets(ch,255,tfile);
		if(strstr(ch, "for user")!=NULL&&strstr(ch, rdata)!=NULL){
			line++;
		}
	}
	fclose(tfile);
	tfile = fopen("/var/log/auth.log", "r");
    if(line>0){
		char ch[255];
		int i = 0;
		while(fgets(ch,255,tfile)){
			// fgets(ch,255,tfile);
			if(strstr(ch, "for user")){
				sscanf(ch, "%s%s%s%*s%s%*s%*s%s%*s%*s%s%*[^\n]\n", a[i], b[i], c[i], session[i], status[i],user[i]);
				double volana = (strncmp(a[i],"Sep",3)==0)?9:(strncmp(a[i],"Oct",3)==0)?10:1;
				(strncmp(a[i],"Sep",3)==0)?strcpy(a[i],"Septambra"):(strncmp(a[i],"Oct",3)==0)?strcpy(a[i],"Oktobra"):strcpy(a[i],"");
				char andro[20];
				strcpy(andro,joursSemaine(2023, volana, atof(b[i])));
				sprintf(date[i], "%s %s %s 2023 tamin'ny %s", andro, b[i], a[i], c[i]);
				session[i] = strtok(session[i],"[]:");
				user[i] = strtok(user[i],"(");
				if(strcmp(rdata, user[i])==0){
					date1[j]=date[i];
					session1[j]=session[i];
					status1[j]=status[i];
					user1[j]=user[i];
					j++;
				}
			}
			i++;
		}
		printf("<table style=\"width: 60vw;\">");
		printf("<tr style=\"height: 2vw;font-weight: bolder;background-color: #111;color: #ddd;\"><td>Date</td><td>Session</td><td>Status</td><td>User</td></tr>");
		int en = (page*10>j)?j:page*10;
		for(int i=(page-1)*10;i<en;i++){
			char loko[20];
			char loko1[20];
			(strcmp(status1[i],"opened")==0)?strcpy(loko,""):strcpy(loko,"#111");
			(strcmp(status1[i],"opened")==0)?strcpy(loko1,""):strcpy(loko1,"#fff");
			printf("<tr style=\"margin: 2vw;height: 2vw;background-color: %s;color: %s;\"><td>%s</td><td>%s</td><td>%s</td><td><a href=\"http://www.find_user.mg/cgi-bin/find_user.cgi?utilisateur=%s\">%s</a></td></tr>", loko, loko1, date1[i], session1[i], status1[i], rdata, user1[i]);
		}
		printf("</table>");
		printf("<div class=\"page\">");
		int end = (page<=5)?10:(page+5>j/10)?j/10:page+5;
		int start = (page<=5)?1:(page+5>j/10)?j/10-9:page-5;
		printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d&user=%s\" class=\"next\">Prev<a/>", rdata, page-1>0?page+1:page, ch1);
		for(int i=start;i<=end;i++){
			char lokony[20];
			(i==page)?strcpy(lokony, "#f00"):strcpy(lokony, "000");
			printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d&user=%s\" style=\"color: %s\">%d<a/>", rdata, i, ch1, lokony, i);
		}
		printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d&user=%s\" class=\"next\">Next<a/>", rdata, page+1<j/10?page+1:page, ch1);
		printf("</div><a class=\"in abtn\" href=\"http://www.login.mg/cgi-bin/find_auth.cgi?user=%s\">Rechercher</a>", ch1);
		printf("</div></div>");
	}
	else{
		printf("<p style=\"font-size: 1.5vw;color: #f00;\">Utilisateur introuvable!</p>");
		printf("<a class=\"in btn\" href=\"http://www.login.mg/cgi-bin/find_auth.cgi?user=%s\">Rechercher</a>", ch1);
		printf("</div></div>");
	}
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

char* joursSemaine(double year, double mounth, double day){
	char* andro = malloc(20);
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	for(int i=1;i<=year;i++){
		if(year>1&&year<400&&i==1){
			continue;
		}
		if(year>1){
			if((((i-1)%400)==0)||((((i-1)%4)==0)&&(((i-1)%100)!=0))){
				a+=2;
			}
			else{
				a+=1;
			}
		}
	}
	b = a%7;
	c = (int)(mounth);
	if((((int)(year)%400)==0)||((((int)(year)%4)==0)&&(((int)(year)%100)!=0))){
			e = 0;
	}
	else{
			e = -1;
	}
	switch(c){
		case 1: d=-1;break;case 2: d=30;break;case 3: d=59+e;break;case 4: d=90+e;break;case 5: d=120+e;break;case 6: d=151+e;break;case 7: d=181+e;break;case 8: d=212+e;break;case 9: d=243+e;break;case 10: d=273+e;break;case 11: d=304+e;break;case 12: d=334+e;break;
	}
	f = (d + (int)(day) + b)%7;
	if((year>=100&&year<200)||(year>=400&&year<500)||(year>=1000&&year<1100)||(year>=1300&&year<1400)){
		f = (f>=4) ? f-1 : f+1;
	}
	if((year>=200&&year<300)||(year>=500&&year<600)||(year>=900&&year<1000)){
		f = (f>=4) ? f-2 : f+2;
	}
	if((year>=300&&year<400)||(year>=600&&year<700)||(year>=800&&year<900)||(year>=1500&&year<1600)){
		f = (f>=4) ? f-3 : f+3;
	}
	if((year>=700&&year<800)){
		f = (f>=4) ? f+3 : f-3;
	}
	f = (f<0) ? f+7 : f%7;
	switch(f){
		case 0: andro = "Asabotsy "; break;
		case 1: andro = "Alahady "; break;
		case 2: andro = "Alatsinainy "; break;
		case 3: andro = "Talata "; break;
		case 4: andro = "Alarobia "; break;
		case 5: andro = "Alakamisy "; break;
		case 6: andro = "Zoma "; break;
	}
	
	return andro;
}
