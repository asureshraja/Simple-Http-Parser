#include<string.h>
struct headers{
        int path;
        int minor_version;
        int keepalive;
        int host;
        int expect;
        int date;
        int method;
        int user_agent;
        int upgrade;
        int forwarded;
        int from;
        int warning;
        int pragma;
        int range;
        int referer;
        int via;
        int origin;
        int max_forwards;
        int te;
        int if_match;
        int if_none_match;
        int if_range;
        int unmodified_since;
        int if_modified_since;
        int proxy_authorization;
        int content_type;
        int content_length;
        int content_md5;
        int cookie;
        int accept;
        int accept_charset;
        int accept_encoding;
        int accept_language;
        int accept_datetime;
        int authorization;
        int cache_control;
        int connection;
        int body_start;
};

// parse headers from specified position
void parse_headers_from(struct headers *req,char *sample,int start){
        parse_headers(req,&sample[start],strlen(&sample[start]));
}

// parse headers to the given length
void parse_headers(struct headers *req,char *sample,int length){
        //method parsing
        int i=0;
        if (sample[i]=='P') {
                if (i+1<length) {i++;}else{i=length;}
                if (sample[i]=='O') {
                        req->method=i-1;
                        if (i+3<length) {i=i+3;}else{i=length;}
                        sample[i]='\0';
                        if (i+1<length) {i=i+1;}else{i=length;}
                }
                else if (sample[i]=='U') {
                        req->method=i-1;
                        if (i+2<length) {i=i+2;}else{i=length;}
                        sample[i]='\0';
                        if (i+1<length) {i=i+1;}else{i=length;}
                }else{i=length;}
        }
        else if (sample[i]=='G') {
                req->method=i;
                if (i+3<length) {i=i+3;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else if (sample[i]=='O') {
                req->method=i;
                if (i+7<length) {i=i+7;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else if (sample[i]=='H') {
                req->method=i;
                if (i+4<length) {i=i+4;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else if (sample[i]=='D') {
                req->method=i;
                if (i+6<length) {i=i+6;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else if (sample[i]=='T') {
                req->method=i;
                if (i+5<length) {i=i+5;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else if (sample[i]=='C') {
                req->method=i;
                if (i+7<length) {i=i+7;}else{i=length;}
                sample[i]='\0';
                if (i+1<length) {i=i+1;}else{i=length;}
        }
        else{
                i=length;
        }
        //end of method parsing

        //start of path parsing
        req->path=i;
        while (sample[i]!=' ') {
                i++;
        }
        sample[i]='\0';
        if (i+1<length) {i=i+1;}else{i=length;}
        //end of path parsing

        //start of minor version parsing
        if (sample[i]=='H') {
                req->minor_version=i+7;
                if (i+8<length) {i=i+8;}else{i=length;}
                sample[i]='\0';
                if (i+2<length) {i=i+2;}else{i=length;} //moving next to  \r\n
        }else{
                i=length;
        }
        //end of minor version parsing


        while(i < length) {

                //start of parsing accept headers
                if (sample[i]=='A') {
                        if (i+6<length) {i=i+6;}else{break;}
                        if (sample[i]=='-') {
                                if (i+1<length) {i=i+1;}else{break;}
                                if (sample[i]=='C') {
                                        if (i+7<length) {i=i+7;}else{break;}
                                        if (sample[i]==':') {
                                                if (i+1<length) {i=i+1;}else{break;}
                                                if (sample[i]==' ') {
                                                        if (i+1<length) {i=i+1;}else{break;}
                                                }
                                                req->accept_charset=i;
                                                while (i<length && sample[i]!='\r') {
                                                        i++;
                                                }
                                                sample[i]='\0';
                                                if (sample[i-1]==' ') {
                                                        sample[i-1]='\0';
                                                }
                                                if (i+2<length) {i=i+2;}else{break;}
                                        }
                                }else if (sample[i]=='E') {
                                        if (i+8<length) {i=i+8;}else{break;}
                                        if (sample[i]==':') {
                                                if (i+1<length) {i=i+1;}else{break;}
                                                if (sample[i]==' ') {
                                                        if (i+1<length) {i=i+1;}else{break;}
                                                }
                                                req->accept_encoding=i;
                                                while (i<length && sample[i]!='\r') {
                                                        i++;
                                                }
                                                sample[i]='\0';
                                                if (sample[i-1]==' ') {
                                                        sample[i-1]='\0';
                                                }
                                                if (i+2<length) {i=i+2;}else{break;}
                                        }
                                }else if (sample[i]=='L') {
                                        if (i+7<length) {i=i+7;}else{break;}
                                        if (sample[i]==':') {
                                                if (i+1<length) {i=i+1;}else{break;}
                                                if (sample[i]==' ') {
                                                        if (i+1<length) {i=i+1;}else{break;}
                                                }
                                                req->accept_language=i;
                                                while (i<length && sample[i]!='\r') {
                                                        i++;
                                                }
                                                sample[i]='\0';
                                                if (sample[i-1]==' ') {
                                                        sample[i-1]='\0';
                                                }
                                                if (i+2<length) {i=i+2;}else{break;}
                                        }
                                }else if (sample[i]=='D') {
                                        if (i+7<length) {i=i+7;}else{break;}
                                        if (sample[i]==':') {
                                                if (i+1<length) {i=i+1;}else{break;}
                                                if (sample[i]==' ') {
                                                        if (i+1<length) {i=i+1;}else{break;}
                                                }
                                                req->accept_datetime=i;
                                                while (i<length && sample[i]!='\r') {
                                                        i++;
                                                }
                                                sample[i]='\0';
                                                if (sample[i-1]==' ') {
                                                        sample[i-1]='\0';
                                                }
                                                if (i+2<length) {i=i+2;}else{break;}
                                        }
                                }else{
                                        break;
                                }
                        }else if (sample[i]==':') {
                                if (i+1<length) {i=i+1;}else{break;}
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->accept=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='i') {
                                if (i+7<length) {i=i+7;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;}
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->authorization=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else{
                                break;
                        }
                        //end of parsing accept headers
                }//start of parsing headeres starting with C
                 else if (sample[i]=='C') {
                         if (i+4<length) {i=i+4;}else{break;}
                         if (sample[i]=='e') {
                                 if (i+1<length) {i=i+1;}else{break;}
                                 if (sample[i]=='-') {
                                         //Cache-Control
                                         if (i+7<length) {i=i+7;}else{break;}
                                         if (i+1<length) {i=i+1;}else{break;} //colon
                                         if (sample[i]==' ') {
                                                 if (i+1<length) {i=i+1;}else{break;}
                                         }
                                         req->cache_control=i;
                                         while (i<length && sample[i]!='\r') {
                                                 i++;
                                         }
                                         sample[i]='\0';
                                         if (sample[i-1]==' ') {
                                                 sample[i-1]='\0';
                                         }
                                         if (i+2<length) {i=i+2;}else{break;}
                                 }else if (sample[i]=='c') {
                                         //Connection
                                         if (i+4<length) {i=i+4;}else{break;}
                                         if (i+1<length) {i=i+1;}else{break;} //colon
                                         if (sample[i]==' ') {
                                                 if (i+1<length) {i=i+1;}else{break;}
                                         }
                                         req->connection=i;
                                         while (i<length && sample[i]!='\r') {
                                                 i++;
                                         }
                                         sample[i]='\0';
                                         if (sample[i-1]==' ') {
                                                 sample[i-1]='\0';
                                         }
                                         if (i+2<length) {i=i+2;}else{break;}
                                 }else if (sample[i]=='n') {
                                         //content headers
                                         if (i+3<length) {i=i+3;}else{break;}
                                         if (sample[i]=='L') {
                                                 //Content-Length
                                                 if (i+6<length) {i=i+6;}else{break;}
                                                 if (i+1<length) {i=i+1;}else{break;} //colon
                                                 if (sample[i]==' ') {
                                                         if (i+1<length) {i=i+1;}else{break;}
                                                 }
                                                 req->content_length=i;
                                                 while (i<length && sample[i]!='\r') {
                                                         i++;
                                                 }
                                                 sample[i]='\0';
                                                 if (sample[i-1]==' ') {
                                                         sample[i-1]='\0';
                                                 }
                                                 if (i+2<length) {i=i+2;}else{break;}
                                         }else if (sample[i]=='M') {
                                                 //Content-MD5
                                                 if (i+3<length) {i=i+3;}else{break;}
                                                 if (i+1<length) {i=i+1;}else{break;} //colon
                                                 if (sample[i]==' ') {
                                                         if (i+1<length) {i=i+1;}else{break;}
                                                 }
                                                 req->content_md5=i;
                                                 while (i<length && sample[i]!='\r') {
                                                         i++;
                                                 }
                                                 sample[i]='\0';
                                                 if (sample[i-1]==' ') {
                                                         sample[i-1]='\0';
                                                 }
                                                 if (i+2<length) {i=i+2;}else{break;}

                                         }else if (sample[i]=='T') {
                                                 //Content-Type
                                                 if (i+4<length) {i=i+4;}else{break;}
                                                 if (i+1<length) {i=i+1;}else{break;} //colon
                                                 if (sample[i]==' ') {
                                                         if (i+1<length) {i=i+1;}else{break;}
                                                 }
                                                 req->content_type=i;
                                                 while (i<length && sample[i]!='\r') {
                                                         i++;
                                                 }
                                                 sample[i]='\0';
                                                 if (sample[i-1]==' ') {
                                                         sample[i-1]='\0';
                                                 }
                                                 if (i+2<length) {i=i+2;}else{break;}
                                         }else{
                                                 break;
                                         }
                                 }else{
                                         break;
                                 }
                         }else if (sample[i]=='e') {
                                 //cookie
                                 if (i+3<length) {i=i+3;}else{break;}
                                 if (i+1<length) {i=i+1;}else{break;} //colon
                                 if (sample[i]==' ') {
                                         if (i+1<length) {i=i+1;}else{break;}
                                 }
                                 req->cookie=i;
                                 while (i<length && sample[i]!='\r') {
                                         i++;
                                 }
                                 sample[i]='\0';
                                 if (sample[i-1]==' ') {
                                         sample[i-1]='\0';
                                 }
                                 if (i+2<length) {i=i+2;}else{break;}
                         }else{
                                 break;
                         }
                        //other headers
                }else if (sample[i]=='H') {
                        //host header
                        if (i+4<length) {i=i+4;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->host=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='D') {
                        //Date header
                        if (i+4<length) {i=i+4;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->date=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='E') {
                        //Expect header
                        if (i+6<length) {i=i+6;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->expect=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='U') {
                        //Header starts with U
                        if (i+4<length) {i=i+4;}else{break;}
                        if (sample[i]=='-') {
                                //User-Agent
                                if (i+6<length) {i=i+6;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->user_agent=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else if (sample[i]=='a') {
                                //Upgrade
                                if (i+3<length) {i=i+3;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->upgrade=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else{
                                break;
                        }
                }else if (sample[i]=='F') {
                        //Header starts with F
                        if (i+1<length) {i=i+1;}else{break;}
                        if (sample[i]=='o') {
                                //Forwarded
                                if (i+8<length) {i=i+8;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->forwarded=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else if (sample[i]=='r') {
                                if (i+3<length) {i=i+3;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->from=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else{
                                break;
                        }
                }else if (sample[i]=='P') {
                        //Header starts with P
                        if (i+2<length) {i=i+2;}else{break;}
                        if (sample[i]=='a') {
                                //pragma
                                if (i+4<length) {i=i+4;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->pragma=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else if (sample[i]=='o') {
                                if (i+17<length) {i=i+17;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->proxy_authorization=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else{
                                break;
                        }
                }else if (sample[i]=='R') {
                        //Header starts with R
                        if (i+1<length) {i=i+1;}else{break;}
                        if (sample[i]=='a') {
                                //range
                                if (i+4<length) {i=i+4;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->range=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else if (sample[i]=='e') {
                                //referer
                                if (i+6<length) {i=i+6;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->referer=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else{
                                break;
                        }
                }else if (sample[i]=='V') {
                        //Via header
                        if (i+3<length) {i=i+3;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->via=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='W') {
                        //Warning header
                        if (i+7<length) {i=i+7;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->warning=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='M') {
                        //Max-Forwards header
                        if (i+12<length) {i=i+12;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->max_forwards=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='O') {
                        //Origin header
                        if (i+6<length) {i=i+6;}else{break;}
                        if (i+1<length) {i=i+1;}else{break;} //colon
                        if (sample[i]==' ') {
                                if (i+1<length) {i=i+1;}else{break;}
                        }
                        req->origin=i;
                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        sample[i]='\0';
                        if (sample[i-1]==' ') {
                                sample[i-1]='\0';
                        }
                        if (i+2<length) {i=i+2;}else{break;}
                }else if (sample[i]=='\r') {
                        //body start
                        if (i+2<length) {i=i+2;}else{break;}
                        req->body_start=i;
                        if (length-i>=req->content_length) {
                                //full body received
                                if (i+req->content_length-1<length) {
                                        sample[i+req->content_length-1]='\0';
                                }
                        }

                        while (i<length && sample[i]!='\r') {
                                i++;
                        }
                        if (i+2<length) {i=i+2;}else{break;}


                }else if (sample[i]=='T') {
                        //TE header
                        if (i+1<length) {i=i+1;}else{break;}
                        if(sample[i]=='E'){
                                if (i+1<length) {i=i+1;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->origin=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='r') {
                                //Transfer-Encoding
                                if (i+16<length) {i=i+16;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->origin=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else{
                                break;
                        }

                }else if (sample[i]=='I') {
                        //If headers
                        if (i+6<length) {i=i+6;}else{break;}
                        if(sample[i]=='c'){
                                //if-match
                                if (i+1<length) {i=i+1;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->if_match=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='i') {
                                //If-modified-since
                                if (i+11<length) {i=i+11;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->if_modified_since=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='e') {
                                //If-None-Match
                                if (i+7<length) {i=i+7;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->if_none_match=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='g') {
                                //If-range
                                if (i+2<length) {i=i+2;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->if_range=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }else if (sample[i]=='o') {
                                //If-unmodified-since
                                if (i+13<length) {i=i+13;}else{break;}
                                if (i+1<length) {i=i+1;}else{break;} //colon
                                if (sample[i]==' ') {
                                        if (i+1<length) {i=i+1;}else{break;}
                                }
                                req->unmodified_since=i;
                                while (i<length && sample[i]!='\r') {
                                        i++;
                                }
                                sample[i]='\0';
                                if (sample[i-1]==' ') {
                                        sample[i-1]='\0';
                                }
                                if (i+2<length) {i=i+2;}else{break;}
                        }
                        else{
                                break;
                        }

                }
                else{
                        while (sample[i]!='\r' & i<length) {
                                i++;
                        }
                        if (i+2<length) {i=i+2;}else{break;} //moving next to  \r\n
                }

                // // while (i<length && sample[i]!='\r') {
                // //         i++;
                // // }
                // // if (i+2<length) {i=i+2;}else{break;} //moving next to  \r\n
                // printf("%s\n",&sample[i] );
                //
        }//end of while

}
