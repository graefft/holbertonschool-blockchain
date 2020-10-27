#include "blockchain.h"

/**
 * blockchain_serialize - serializes a Blockchain into a file
 *
 * @blockchain: points to the Blockchain to serialize
 * @path: path to a file to serialize the Blockchain into
 * Return: 0 on success or -1 on failure
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	int fd;

	if (!blockchain || !blockchain->chain || !path)
		return (-1);

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0700);
	if (fd == -1)
		return (-1);
	/* 0x00	4	hblk_magic	48 42 4c 4b	*/
	write(fd, HBLK_MAGIC, strlen(HBLK_MAGIC));
	/* 0x04 3	hblk_version x.y        */
	write(fd, HBLK_VERSION, strlen(HBLK_VERSION));

	close(fd);
	return (0);
}
