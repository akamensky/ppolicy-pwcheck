#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <portable.h>
#include <slap.h>

const char lowerCase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char upperCase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char digits[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const char special[28] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', ':', ';', '<', '>', ',', '.', '?', '/', '\\', '|', '-', '_', '+', '=', '[', ']', '{', '}'};

int check_password (char *pPasswd, char **ppErrStr, Entry *pEntry);
int isLower(char c);
int isUpper(char c);
int isDigit(char c);
int isSpecial(char c);

int check_password (char *pPasswd, char **ppErrStr, Entry *pEntry)
{
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    for (int i = 0; i < strlen(pPasswd) ; ++i) {
        if (isLower(pPasswd[i])) {
            hasLower++;
            continue;
        }
        if (isUpper(pPasswd[i])) {
            hasUpper++;
            continue;
        }
        if (isDigit(pPasswd[i])) {
            hasDigit++;
            continue;
        }
        if (isSpecial(pPasswd[i])) {
            hasSpecial++;
            continue;
        }
    }

    if (hasLower > 0 && hasUpper > 0 && hasDigit > 0) {
        return (LDAP_SUCCESS);
    }

    return (EXIT_FAILURE);
}

int isLower(char c)
{
    int result = 0;
    for (int i = 0; i < sizeof(lowerCase); ++i) {
        if (lowerCase[i] == c){
            result = 1;
            break;
        }
    }
    return result;
}

int isUpper(char c)
{
    int result = 0;
    for (int i = 0; i < sizeof(upperCase); ++i) {
        if (upperCase[i] == c){
            result = 1;
            break;
        }
    }
    return result;
}

int isDigit(char c)
{
    int result = 0;
    for (int i = 0; i < sizeof(digits); ++i) {
        if (digits[i] == c){
            result = 1;
            break;
        }
    }
    return result;
}

int isSpecial(char c)
{
    int result = 0;
    for (int i = 0; i < sizeof(special); ++i) {
        if (special[i] == c){
            result = 1;
            break;
        }
    }
    return result;
}
