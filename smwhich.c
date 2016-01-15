#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
main(int argc,char* argv[])
{
    if(argc<3){
        char *tokens;
        char *str,errl[512];
        char *delim=":",pathstr[1024];
        int i=0;
        str=getenv("PATH");
        strcpy(errl,str);
        tokens=strtok(str,delim);
        
        while(tokens!=NULL)
        {
            strcpy(pathstr,tokens);
            strcat(pathstr,"/");
            strcat(pathstr,argv[1]);
            
            if(access(pathstr,X_OK)!=-1)
            {
                printf("%sn",pathstr);
                break;
            }
            tokens=strtok(NULL,delim);
            if(tokens==NULL)
            {
                printf("smwhich: no %s inn(%s:.)n",argv[1],errl);
            }
            
            i++;
        }
        
    }
}
