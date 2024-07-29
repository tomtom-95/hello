// first attempt in hashset implementation
// the hashset must be able to store number between 0 and 10 ** 6

#ifndef HASHSET_C
#define HASHSET_C

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BUCKET_SIZE 1001
#define BUCKET_CNT  1000

typedef struct Bucket
{
    int *start;
    int pos;
} Bucket;

typedef struct HashSet
{
    int *data;
    Bucket buckets[BUCKET_CNT];
} HashSet;

HashSet
HashSetInit(void)
{
    HashSet hash_set;
    hash_set.data = malloc((BUCKET_CNT * BUCKET_SIZE) * sizeof(*(hash_set.data)));
    for (int i = 0; i < BUCKET_CNT; i++)
    {
        hash_set.buckets[i].start = hash_set.data + BUCKET_SIZE * i;
        hash_set.buckets[i].pos = 0;
    }
    return hash_set;
}

bool
HashSetIsValueContained(HashSet *hash_set, int value)
{
    int idx_bucket = value % BUCKET_CNT;
    Bucket *bucket = &((hash_set -> buckets)[idx_bucket]);
    for (int i = 0; i < (bucket -> pos); i++)
    {
        if (*((bucket -> start) + i) == value)
        {
            return true;
        }
    }

    return false;
}

void
HashSetInsert(HashSet *hash_set, int value)
{
    if (HashSetIsValueContained(hash_set, value))
    {
        return;
    }
    else
    {
        int idx_bucket = value % BUCKET_CNT;
        Bucket *bucket = &((hash_set -> buckets)[idx_bucket]);
        *((bucket -> start) + (bucket -> pos)) = value;
        (bucket -> pos)++;
    }
}

void
HashSetRemove(HashSet *hash_set, int value)
{
    if (HashSetIsValueContained(hash_set, value))
    {
        return;
    }
    else
    {
        int idx_bucket = value % BUCKET_CNT;
        Bucket *bucket = &((hash_set -> buckets)[idx_bucket]);
        for (int i = 0; i < bucket -> pos + 1; i++)
        {
            if (*((bucket -> start) + i) == value)
            {
                for (int j = i; j < bucket -> pos; j++)
                {
                    *((bucket -> start) + j) = *((bucket -> start) + j + 1);
                }

                (bucket -> pos)--;
            }
        }
    }
}

int main(int argc, char **argv)
{
    HashSet hash_set = HashSetInit();
    HashSetInsert(&hash_set, 5);
    HashSetInsert(&hash_set, 10);
    HashSetRemove(&hash_set, 10);

    return 0;
}

#endif // HASHSET_C