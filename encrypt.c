#include "encrypt.h"
unsigned char *encrypt(unsigned char *key, unsigned char *nonce, unsigned char * MESSAGE, unsigned int MESSAGE_LEN) {
  int CIPHERTEXT_LEN = crypto_secretbox_MACBYTES + MESSAGE_LEN;
  unsigned char *ciphertext = (unsigned char*)malloc(CIPHERTEXT_LEN * sizeof(char));

  randombytes_buf(nonce, sizeof nonce);
  crypto_secretbox_easy(ciphertext, MESSAGE, MESSAGE_LEN, nonce, key);
  
  return ciphertext;
}

unsigned char *decrypt(unsigned char *key, unsigned char *nonce, unsigned char * ciphertext, unsigned int MESSAGE_LEN){
  int CIPHERTEXT_LEN = crypto_secretbox_MACBYTES + MESSAGE_LEN;
  unsigned char *decrypted = (unsigned char*)malloc(MESSAGE_LEN * sizeof(char));

  if (crypto_secretbox_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN, nonce, key) != 0) 
    printf("Error\n");

    return decrypted;
}


unsigned char *authenticateGen(unsigned char *key, unsigned char * MESSAGE, unsigned int MESSAGE_LEN){
  unsigned char *mac = (unsigned char*)malloc(crypto_auth_BYTES * sizeof(char));
  
  crypto_auth(mac, MESSAGE, MESSAGE_LEN, key);
  return mac;
}
int authenticateVrfy(unsigned char *mac, unsigned char *MESSAGE, unsigned int MESSAGE_LEN, unsigned char *key){
  if (crypto_auth_verify(mac, MESSAGE, MESSAGE_LEN, key) != 0) {
    printf("Mac error\n");
    return -1;
  } else {
    printf("Mac OK\n");
    return 0;
  }
}
