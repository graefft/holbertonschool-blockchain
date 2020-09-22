#include "hblk_crypto.h"

/**
 * ec_to_pub - extracts the public key from an EC_KEY opaque structure
 *
 * @key: pointer to EC_KEY structure to retrieve public key from
 * @pub: address at which to store the extracted public key
 *
 * Return: pointer to pub, or NULL on failure
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	return (NULL);
}
