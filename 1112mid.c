#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strrmv(char *source, int c){
    char *str = source;
    int len = strlen(str);
    for(int i=0;i<strlen(str);i++){
        if((int) *(str+i) == c){
            for(int j=i;j<strlen(str)-1;j++){
                *(str+j) = *(str+j+1);
            }
            *(str+strlen(str)-1) = '\0';
            i--;
        }
    }
    return str;
}

int palindrome(char *source){
    int length = strlen(source);
    char stack[length];
    int midlength = length/2;
    int mid = midlength;

    for(int i=0;i<mid;i++){
        *(stack + i) = *(source + i);
    }
    if(strlen(source) % 2 == 1){
        mid++;
    }
    for(int i=mid;i<length;i++,midlength--){
        if(*(stack + midlength - 1) != *(source + i)){
            return 0;
        }
    }
    return 1;
}

int parentheses(char *paren){
    int size = strlen(paren);
    char stack[size];
    int length = 0;

    for(int i=0;i<size;i++){
        if(*(paren + i) == '('){
            *(stack + length) = '(';
            length++;
        }else if(*(paren + i) == ')'){
            *(stack + length - 1) = '\0';
            length--;
        }
    }
    return !length;
}

int main()
{
    char s1[] = "Hello!My name is Wang Shao-Lei";
    char s2[] = "ABBCA";
    char s3[] = "((()))";
    char *sp = s1;
    int c = '-';
    sp = strrmv(s1,c);
    printf("%s\n",sp);
    sp = s2;
    printf("%d\n",palindrome(sp));
    sp = s3;
    printf("%d\n",parentheses(sp));
    system("PAUSE");
    return 0;
}
