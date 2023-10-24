#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#define col 1000
char **alouer(char **cfile1);
void write(FILE *tfile, char* data, int a, char **b, char **c, char **f, char **g, char **h, long int* d, long int* e);

int main(){
    printf("Content-type:text/html\n\n");
    char* data = getenv("QUERY_STRING");
	FILE *tfile;
	tfile = fopen("/etc/passwd", "r");
	char * isa = malloc(255);
	FILE *asa = popen("cat /etc/passwd | wc -l", "r");
	fgets(isa, 255,  asa);
	int a = atoi(isa);
	char** b = NULL;b = alouer(b); char**  c = NULL;c = alouer(c);char** f = NULL;f = alouer(f);char** g = NULL;g = alouer(g);char** h = NULL;h = alouer(h); 
	long int* d = malloc(ta);long int* e = malloc(ta);
	printf("<html><head> <style>body{width: 99vw;height: 98vh;background-color: #d4e694;display: flex;justify-content: center;align-items: center;}.main{background-color: aqua;width: 50vw;height: 20vw;border-radius: 2vw;display: flex;justify-content: center;align-items: center;flex-direction: column;font-size: 1vw;text-align: center;box-shadow: 2px 2px 5px #000;}.btn{background-color: #0f0;border-radius: .7vw;width: 10vw;height: 1.5vw;font-size: 1vw;color: #fff;font-weight: bolder;box-shadow: 2px 2px 2px #000;}</style></head><body style=\"display:flex;flex-direction:column;justify-content:center;align-items:center;height:100vh;\"><h1>Les informations de l'utilisateur</h1></br>");
	write(tfile, data, a, b, c, f, g, h, d, e);
	printf("</body></html>");
	fclose(tfile);
		
	return 0;
}

void write(FILE *tfile, char* data, int a, char **b, char **c, char **f, char **g, char **h, long int* d, long int* e){
	printf("<div class=\"main\">");
    int index = -1;
	for(int i=0;i<a;i++){
		char ch[100];
		fgets(ch,100,tfile);
		sscanf(ch, "%[^:]:%[^:]:%ld:%ld:%[^:]:%[^:]:%[^\n]\n", b[i], c[i], d+i, e+i, f[i], g[i], h[i]);
	}
	char rdata[255];
	sscanf(data, "%*[^=]=%s", rdata);
	for(int i=0;i<a;i++){
        if(strcmp(rdata, b[i])==0){
			index = i;
		}
    }
    if(index>=0){
		printf("<h1>%s</h1><h3>Repertoire personnel: %s</h3><h3>Interpreteur bash: %s</h3><h3>Adresse E-mail: %s@mit.mg</h3></tr>", b[index], g[index], h[index], b[index]);
	}
	else{
		printf("<p style=\"color: #f00;\">Utilisateur introuvable!</p>");
	}
	printf("<a class=\"btn\" href=\"http://www.find_user.mg\">Rechercher</a></div>");
}

char **alouer(char **cfile1){
	char **a = (char**)malloc(col*sizeof(char*));
	for(int i=0;i<ta;i++){
		a[i] = malloc(ta);
	}
	return a;
}
