#include <stdio.h>
#include "sodium.h"

//int encrypt(unsigned char key[crypto_secretbox_KEYBYTES], unsigned char nonce[crypto_secretbox_NONCEBYTES], unsigned char * MESSAGE, unsigned int MESSAGE_LEN);
unsigned char *encrypt(unsigned char *key, unsigned char *nonce, unsigned char * MESSAGE, unsigned int MESSAGE_LEN);
unsigned char *decrypt(unsigned char *key, unsigned char *nonce, unsigned char * ciphertext, unsigned int MESSAGE_LEN);

unsigned char *authenticateGen(unsigned char *key, unsigned char * MESSAGE, unsigned int MESSAGE_LEN);
int authenticateVrfy(unsigned char *mac, unsigned char *MESSAGE, unsigned int MESSAGE_LEN, unsigned char *key);
