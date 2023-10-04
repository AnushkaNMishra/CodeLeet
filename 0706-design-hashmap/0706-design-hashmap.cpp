class MyHashMap
{
public:
    vector<vector<int>> myhashMap;

    int buckets, bucketSize;

    MyHashMap()
    {
        buckets = 1000;
        bucketSize = 1000;
        myhashMap = vector<vector<int>>(buckets + 1);
    }

    int getBucketNumber(int key)
    {
        return key % buckets;
    }

    int getBucketSlot(int key)
    {
        return key / bucketSize;
    }

    void put(int key, int value)
    {
        int bucketNumber = getBucketNumber(key);
        int bucketSlot = getBucketSlot(key);

        // bucket not initialized
        if (myhashMap[bucketNumber].size() == 0)
            myhashMap[bucketNumber] = vector<int>(bucketSize + 1, -1);

        myhashMap[bucketNumber][bucketSlot] = value;
    }

    int get(int key)
    {
        int bucketNumber = getBucketNumber(key);
        int bucketSlot = getBucketSlot(key);

        if (myhashMap[bucketNumber].size() == 0)
            return -1;

        return myhashMap[bucketNumber][bucketSlot];
    }

    void remove(int key)
    {
        int bucketNumber = getBucketNumber(key);
        int bucketSlot = getBucketSlot(key);

        if (myhashMap[bucketNumber].size() == 0)
            return;

        myhashMap[bucketNumber][bucketSlot] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */