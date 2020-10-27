#include "blockchain.h"

/**
 * write_block - writes info for a block_t struct to file pointer
 *
 * @node: current block in blockchain to print
 * @file_pointer: file stream to write to
 * Return: 0 on success, -1 on failure
 */
int write_block(llist_node_t node, void *file_pointer)
{
	block_t *block;
	FILE *fp;

	if (!node || !file_pointer)
		return (-1);

	block = node;
	fp = (FILE *)file_pointer;

	fwrite((void *)&block->info, sizeof(block->info), 1, fp);
	fwrite((void *)&block->data.len, sizeof(block->data.len), 1, fp);
	fwrite(block->data.buffer, block->data.len, 1, fp);
	fwrite(block->hash, sizeof(block->hash), 1, fp);
	return (0);
}
/**
 * blockchain_serialize - serializes a Blockchain into a file
 *
 * @blockchain: points to the Blockchain to serialize
 * @path: path to a file to serialize the Blockchain into
 * Return: 0 on success or -1 on failure
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	FILE *fp;
	int blocks, i;
	uint8_t endian;

	if (!blockchain || !blockchain->chain || !path)
		return (-1);

	fp = fopen(path, "w");
	if (!fp)
		return (-1);

	/* 0x00	4	hblk_magic      48 42 4c 4b */
	fwrite(HBLK_MAGIC, strlen(HBLK_MAGIC), 1, fp);
	/* 0x04 3	hblk_version    x.y         */
	fwrite(HBLK_VERSION, strlen(HBLK_VERSION), 1, fp);
	/* 0x07	1	hblk_endian     1 or 2      */
	endian = _get_endianness();
	fwrite(&endian, 1, 1, fp);
	/* 0x08	4	hblk_blocks                 */
	blocks = llist_size(blockchain->chain);
	fwrite(&blocks, sizeof(blocks), 1, fp);
	/* 0x0C n	blocks                      */
	for (i = 0; i < blocks; i++)
	{
		if (write_block(llist_get_node_at(blockchain->chain, i), fp) == -1)
		{
			fclose(fp);
			return (-1);
		}
	}
	fclose(fp);
	return (0);
}
