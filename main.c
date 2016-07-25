#include "httpparser.h"

int main(int argc, char const *argv[]) {
        char* sample;
        sample=malloc(1000);
        strcpy(sample,"POST /test HTTP/1.1\r\nHost: test-domain.com:7017\r\nUser-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.1) Gecko/2008070208 Firefox/3.0.1\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-us,en;q=0.5\r\nAccept-Encoding: gzip,deflate\r\nAccept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\nKeep-Alive: 300\r\nConnection: keep-alive\r\nReferer: http://test-domain.com:7017/index.html\r\nCache-Control: max-age=0\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 4\r\n\r\nbody");

        int length=strlen(sample);
        struct headers *req;
        req = malloc(sizeof(struct headers));

        parse_headers(req, sample, strlen(sample));


        printf("Method=%s\n",&sample[req->method]);
        printf("Path=%s\n",&sample[req->path]);
        printf("minor_version=%s\n",&sample[req->minor_version]);
        printf("content-length=%s\n",&sample[req->content_length]);
        printf("Accept=%s\n",&sample[req->accept]);
        printf("Accept-charset=%s\n",&sample[req->accept_charset]);
        printf("content-type=%s\n",&sample[req->content_type]);
        printf("host=%s\n",&sample[req->host]);
        printf("body_start=%s\n",&sample[req->body_start]);
        // printf("req-%d\n",req->method);
        // printf("req-%d\n",req->path);
        // printf("req-%d\n",req->minor_Version);
        // printf("req-%d\n",req->content_length);
        // printf("req-%d\n",req->content_type);
        return 0;
}
