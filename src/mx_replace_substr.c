#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(str == NULL || sub == NULL || replace == NULL) return NULL;
    char *res = mx_strdup(str);
    char *buff1 = mx_strnew(mx_strlen(str));
    char *buff2 = mx_strnew(mx_strlen(str));
    while(mx_strstr(res,sub) != NULL){
        int i = mx_get_substr_index(res,sub);
        mx_strncpy(buff1, res, i);
        for(int j = 0; j < i + mx_strlen(sub); j++){
            res++;
        }
        mx_strcpy(buff2,res);
        res = "";
        res = mx_strjoin(res, buff1);
        res = mx_strjoin(res, replace);
        res = mx_strjoin(res, buff2);
    }
    free(buff1);
    free(buff2);
    return res;
}

