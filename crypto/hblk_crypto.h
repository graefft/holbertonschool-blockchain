#ifndef __HBLK_CRYPTO__
#define __HBLK_CRYPTO__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <openssl/opensslconf.h>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/sha.h>

#define EC_CURVE NID_secp256k1

#define EC_PUB_LEN 65 /* constant 04 prefix, 32-byte x, 32-byte y */

EC_KEY *ec_create(void);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH]);

#endif  /* __HBLK_CRYPTO__ */
