#include "hblk_crypto.h"

/**
 *
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
	sig_t const *sig)
{
	uint8_t digest[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (0);

	if (!EC_KEY_check_key(key))
		return (0);

	if (!SHA256(msg, msglen, digest))
		return (0);

	return (1);
}
