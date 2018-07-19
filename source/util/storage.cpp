#include "../../include/util/storage.h"
#include "../../include/map/HashMap.h"

Chunk::Chunk(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

int Chunk::getId(int x, int y, int z) {
    return this->blocks[(x << 8) | (y << 4) | z];
}

int hashPos(int x, int y, int z) {
    return z + 31 * (31 * (x) + y);
}

static HashMap<int, Chunk, 128, KeyHasher> loadedChunks;

Chunk getChunk(int x, int y, int z) {
    //man i will never understand c++
    Chunk* c = NULL;
    int hash = hashPos(x, y, z);
    loadedChunks.get(hash, *c);
    return *c;
}
