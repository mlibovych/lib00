#include "libmx.h"

void mx_swap_char(char *s1, char *s2) {
    char c = *s1;
    
    *s1 = *s2;
    *s2 = c;
}
