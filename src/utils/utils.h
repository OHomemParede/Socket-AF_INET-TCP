#ifndef SOCKET_CHAT_UTILS_H
#define SOCKET_CHAT_UTILS_H

#define TRUE 1
#define FALSE 0

typedef struct colors {
    char *end;
    char *black;
    char *red;
    char *green;
    char *yellow;
    char *blue;
    char *purple;
    char *cyan;
    char *white;
} colors_t;
extern colors_t global_colors;

/**
 * @brief output error_msg to stderr and exit program with code 1.
 * 
 * @param error_msg 
 */
void raise_panic(char *error_msg);


/**
 * @brief comparer two strings
 * 
 * @param str_1 
 * @param str_2 
 * @param n 
 * @return TRUE if the strings are equal. FALSE if strings are not equal
 */
int strn_equals(char *str_1, char *str_2, uint32_t n);

#endif