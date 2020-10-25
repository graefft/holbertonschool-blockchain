#include "hblk_crypto.h"

/**
 * ec_sign - signs a given set of bytes using a
 *           given EC_KEY private key
 *
 * @key: EC_KEY structure containing private key to be used
 * @msg: characters to be signed
 * @msglen: number of characters to be signed
 * @sig: address at which to store the signature
 * Return: pointer to signature buffer on success, NULL on failure
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
	sig_t *sig)
{
	uint8_t digest[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (NULL);

	sig->len = (uint8_t)ECDSA_size(key);

	if (!SHA256(msg, msglen, digest))
		return (NULL);

	if (!ECDSA_sign(EC_CURVE, digest, SHA256_DIGEST_LENGTH, sig->sig,
		 (unsigned int *)&(sig->len), (EC_KEY *)key))
		return (NULL);

	return (sig->sig);
}
