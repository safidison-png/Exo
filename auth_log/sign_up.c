#include <stdio.h>

int main(){
    printf("Content-type:text/html\n\n");
    printf("<html><head> <style>body{height: 98vh;width: 99vw;background: linear-gradient(20deg, #000, #151516, #333b35, #000);display: flex;justify-content: center;align-items: center;}.main{display: flex;}.main .hd{color: #fff;margin-right: 5vw;font-family: cursive;font-size: 1.5vw;}form{width: 50vw;height: 20vw;border-radius: .2vw;display: flex;justify-content: center;align-items: center;flex-direction: column;font-size: 1vw;text-align: center;}.in{background-color: #131010;font-family: serif;width: 40vw;height: 4vw;margin: 1vw;border-radius: 5vw;font-size: 1.5vw;padding: .5vw 2vw;border: none;color: #fff;}.btn{height: 4vw;margin: 3vw 0vw 6vw 0vw;background: linear-gradient(3deg, #000, #460833, #f00, #f00, #f00);}</style></head><body>");
    printf("<div class=\"main\">"
                "<div class=\"hd\">"
                "<h1>Signup for free</h1>"
                "<p>Signup to join 20 000 persons for discovering another somethings</p>"
                "</div>"
                "<form action=\"signed_up.cgi\" method=\"get\">"
                    "<input class=\"in\" type=\"text\" name=\"nom\" placeholder=\"Tape your username\">"
                    "<input class=\"in\" type=\"password\" name=\"passwd1\" placeholder=\"Password\">"
                    "<input class=\"in\" type=\"password\" name=\"passwd2\" placeholder=\"Retape password\">"
                    "<input class=\"in btn\" type=\"submit\" value=\"Register\">"
                "</form>"
            "</div>");
    return 0;
}