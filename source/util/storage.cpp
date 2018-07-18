#include "../../include/util/storage.h"

class Chunk {
public:
    int x;
    int y;
    int z;
    char blocks[4096];
    
    Chunk(int x, int y, int z)  {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    int getId(int x, int y, int z)   {
        return this->blocks[(x << 8) | (y << 4) | z];
    }
};
