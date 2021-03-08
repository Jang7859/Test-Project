//
//  main.c
//  71.Simplify Path
//
//  Created by 장재연 on 2021/03/08
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * simplifyPath(char * path){
    int len = strlen(path);
    int buf_cnt, ans_cnt, rm_cnt;
    char buf[3000];
    char r_ans[3000];
    
    buf_cnt = 0; ans_cnt = 0; rm_cnt=0;
    
    //Start from last index.
    for(int i=len-1;i>=0;i--){
        if(path[i]=='/'){
            if(buf_cnt==0) continue; // buffer empty.
            
            //buf_cnt = 0  <-- mean that emptying the buffer.
            if(buf_cnt==1 && buf[0]=='.') buf_cnt = 0;
            else if(buf_cnt==2 && buf[0]=='.' && buf[1] == '.'){ //It increases 'rm_cnt' when the buffer is filled with '..', which can ignore the  following buffer.
                buf_cnt = 0; rm_cnt++;
            }else if(rm_cnt!=0){
                buf_cnt = 0; rm_cnt--;
            }else{
                for(int j=0;j<buf_cnt;j++){
                    r_ans[ans_cnt++] = buf[j];
                }
                r_ans[ans_cnt++] = '/';
                buf_cnt = 0;
            }
        }else{
            buf[buf_cnt++] = path[i];
        }
    }
    
    if(ans_cnt==0){
        char *ans = (char*)malloc(sizeof(char)*2);
        ans[0] = '/';
        ans[1]='\0';
        
        return ans;
    }

    // Testcase  "/AOO/B00/" ->  r_ans = OOB/OOA/ , so "ans" need to be reversed.
    char* ans = (char*)malloc(sizeof(char)*(ans_cnt+1));
    for(int i=ans_cnt-1;i>=0;i--){
        ans[ans_cnt-1-i] = r_ans[i];
    }
    ans[ans_cnt] = '\0';
    return ans; //ans = /AOO/BOO
}
