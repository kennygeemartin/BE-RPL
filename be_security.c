#include <stdio.h>
#include <string.h>

// Mock ECDSA placeholder (for reproducibility)
void sign_message(const char *msg, char *signature) {
    sprintf(signature, "SIG_%lu", strlen(msg));
}

int verify_signature(const char *msg, const char *signature) {
    return strstr(signature, "SIG_") != NULL;
}
