#ifndef STORAGE_H
#define STORAGE_H

class Chunk {
public:
    int x;
    int y;
    int z;
    char blocks[4096];

    Chunk(int x, int y, int z);

    int getId(int x, int y, int z);
    
    ~Chunk()    {
        delete this->blocks;
    }
};

struct KeyHasher {
    unsigned long operator()(const int& k) const {
        return k & 0xFF;
    }
};

#endif /* STORAGE_H */

