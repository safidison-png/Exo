#include <stdio.h>

int main(){
    printf("Content-type:text/html\n\n");
    printf("<html><head> <link rel=\"stylesheet\" href=\"http://www.login.mg/style.css\"><title>Sign up</title></head><body>");
    printf("<div class=\"main\">"
                "<div class=\"hd\">"
                "<h1>Signup for free</h1>"
                "<p>Signup to join 20 000 persons for discovering another somethings</p>"
                "</div>"
                "<form action=\"signed_up.cgi\" method=\"get\">"
                    "<input class=\"in\" type=\"text\" name=\"nom\" placeholder=\"Tape your username\">"
                    "<input class=\"in\" type=\"password\" name=\"passwd1\" placeholder=\"Password\">"
                    "<input class=\"in\" type=\"password\" name=\"passwd2\" placeholder=\"Retape password\">"
                    "<input class=\"in fbtn\" type=\"submit\" value=\"Register\">"
                "</form>"
            "</div>");
    return 0;
}