#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
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
	FILE* tfile1;
	tfile1 = fopen("/home/safidison/Mit/login/conn.csv", "r");
    char ch1[255];
    char loha[1000];
	fgets(ch1,255,tfile1);
    (strcmp(ch1,"none")==0)?strcpy(loha,"<meta http-equiv='refresh' content='2;url=http://www.login.mg/'>"):strcpy(loha,"");
	a = alouer(a);
	b = alouer(b);
	c = alouer(c);
	user = alouer();
	date = alouer();
	session = alouer();
	status = alouer();
    printf("Content-type:text/html\n\n");
	printf("<html><head>%s <style>body{width: 99vw;height: 98vh;background: linear-gradient(20deg, #000, #151516, #333b35, #000);display: flex;justify-content: center;align-items: center;}nav{position: fixed;top: 0vw;left: 0vw;width: 100vw;height: 5vw;border-radius: .5vw;font-family: cursive;height: 2vw;display: flex;color: #fff;}nav h1{font-size: 2vw;margin: 1vw 0vw 0vw 2vw;}nav .icon{background-image: url(http://www.login.mg/index.png);background-size: cover;background-position: center;width: 4.5vw;height: 4vw;border-radius: 50%%;}nav #icon{display: flex;width: 10vw;}nav a{margin: 1vw 1vw 0vw 82vw;font-size: 1.5vw;text-decoration: none;font-family: serif;}.main{display: flex;}.main .hd{color: #fff;margin-right: 5vw;font-family: cursive;font-size: 2vw;padding: 4.5vw}.btn{text-align: center;font-family: serif;width: 40vw;height: 2vw;margin: 1vw;border-radius: 5vw;font-size: 1.5vw;padding: .5vw 2vw;border: none;color: #fff;background: linear-gradient(3deg, #000, #460833, #f00, #f00, #f00);}.aty{display: flex;flex-direction: column;justify-content: center;align-items: center;}table{font-size: 1vw;}.aty a{text-decoration: none;}.page{width: 40vw;justify-content: space-between;padding: 1vw;border: none;display:flex;margin: 1.2vw;font-size: 1.5vw;}.page a{color: #000;font-family: sans-serif;font-weight: bold;}</style></head><body>", loha);
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
                "<a class=\"bt\" href=\"http://www.login.mg/cgi-bin/logout.cgi\">Logout</a>"
            "</nav>", ch1);
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
		printf("<table border style=\"width: 60vw;\">");
		printf("<tr style=\"font-weight: bolder;\"><td>Date</td><td>Session</td><td>Status</td><td>User</td></tr>");
		int en = (page*10>j)?j:page*10;
		for(int i=(page-1)*10;i<en;i++){
			char loko[20];
			char loko1[20];
			(strcmp(status1[i],"opened")==0)?strcpy(loko,""):strcpy(loko,"#000");
			(strcmp(status1[i],"opened")==0)?strcpy(loko1,""):strcpy(loko1,"#fff");
			printf("<tr style=\"background-color: %s;color: %s\"><td>%s</td><td>%s</td><td>%s</td><td><a href=\"http://www.find_user.mg/cgi-bin/find_user.cgi?utilisateur=%s\">%s</a></td></tr>", loko, loko1, date1[i], session1[i], status1[i], rdata, user1[i]);
		}
		printf("</table>");
	}
	else{
		printf("<p style=\"color: #f00;\">Utilisateur introuvable!</p>");
	}
	printf("<div class=\"page\">");
	int end = (page<=5)?10:(page+5>j/10)?j/10:page+5;
	int start = (page<=5)?1:(page+5>j/10)?j/10-9:page-5;
	printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d\">Prev<a/>", rdata, page-1);
	for(int i=start;i<=end;i++){
		char lokony[20];
		(i==page)?strcpy(lokony, "#f00"):strcpy(lokony, "000");
		printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d\" style=\"color: %s\">%d<a/>", rdata, i, lokony, i);
	}
	printf("<a href=\"http://www.login.mg/cgi-bin/auth.cgi?utilisateur=%s&p=%d\">Next<a/>", rdata, page+1);
	printf("</div><a class=\"in btn\" href=\"http://www.login.mg/cgi-bin/find_auth.cgi\">Rechercher</a>");
	printf("</div></div>");
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
