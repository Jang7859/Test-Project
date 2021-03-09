//
//  main.c
//  1332. Remove Palindromic Subsequences
//
//  Created by 장재연 on 2021/03/09.
//

#include <stdio.h>

int removePalindromeSub(char * s){
    int len = strlen(s);
    if(!len) return 0;
    for(int i=0, j=len-1;i<j;i++, j--){
        if(s[i]!=s[j])return 2;
    }
    return 1;
}

int main(void) {
    char *s = "ababa";
    printf("%d\n", removePalindromeSub(s));
    return 0;
}
