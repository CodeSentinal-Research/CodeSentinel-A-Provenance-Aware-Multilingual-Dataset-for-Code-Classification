#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

static int cmpKey(int s1, int i1, int s2, int i2) {
    if (s1 != s2) return (s1 < s2) ? -1 : 1;
    if (i1 != i2) return (i1 < i2) ? -1 : 1;
    return 0;
}

struct IndexEntry {
    int section;
    int id;
    int BID;
};

struct DataEntry {
    int section;
    int id;
    int value;
};

struct NonLeafNode {
    int BID;
    int nextLevelBID;
    vector<IndexEntry> entries;
};

struct LeafNode {
    int BID;
    int nextBID;
    vector<DataEntry> entries;
};

class BTree {
public:
    BTree(const char *fileName);
    BTree(const char *fileName, int blockSize);
    int offset(int BID);
    int allocBID();
    void writeHeader();
    void writeNonLeaf(NonLeafNode &nonLeaf);
    void writeLeaf(LeafNode &leaf);
    NonLeafNode readNonLeaf(int BID);
    LeafNode readLeaf(int BID);
    LeafNode findLeaf(int section, int id, vector<int>& path);
    void insertIntoLeaf(LeafNode &leaf, const DataEntry &entry);
    void insertIntoNonLeaf(NonLeafNode &nonLeaf, const IndexEntry &entry);
    void insertIntoParent(vector<int> &path, int leftBID, int upSection, int upId, int rightBID);
    bool insert(int section, int id, int value);
    int search(int section, int id);
    void rangeSearch(int sSec, int sId, int eSec, int eId, vector<string> &results);
    void print(FILE *out);

private:
    const char *fileName;
    int blockSize;
    int rootBID;
    int depth;
    int L;
};

int main(int argc, char* argv[]) {
    char command = argv[1][0];
    char *btreeBinaryFile = argv[2];

    switch (command) {
        case 'c': {
            /* create index file */
            int blockSize = atoi(argv[3]);
            BTree myBtree(btreeBinaryFile, blockSize);
            break;
        }
        case 'i': {
            /* insert records from [records data file] */
            char *recordsDataFile = argv[3];
            BTree myBtree(btreeBinaryFile);
            FILE *pFile = fopen(recordsDataFile, "r");
            int section, id, value;
            while (fscanf(pFile, "%d,%d,%d", &section, &id, &value) == 3) {
                myBtree.insert(section, id, value);
            }
            fclose(pFile);
            break;
        }
        case 's':
        {
            /* point search; write results to output */
            char *inputTextFile = argv[3];
            char *outputTextFile = argv[4];

            BTree myBtree(btreeBinaryFile);
            FILE *in = fopen(inputTextFile, "r");
            FILE *out = fopen(outputTextFile, "w");
            int section, id;
            while (fscanf(in, "%d,%d", &section, &id) == 2) {
                int v = myBtree.search(section, id);
                if (v != -1) fprintf(out, "%d,%d,%d\n", section, id, v);
            }
            fclose(in);
            fclose(out);
            break;
        }
        case 'r':
        {
            /* range search; write results to output */
            char *inputTextFile = argv[3];
            char *outputTextFile = argv[4];
            BTree myBtree(btreeBinaryFile);
            FILE *rangeIn = fopen(inputTextFile, "r");
            FILE *rangeOut = fopen(outputTextFile, "w");
            int sSec, sId, eSec, eId;
            while (fscanf(rangeIn, "%d,%d,%d,%d", &sSec, &sId, &eSec, &eId) == 4) {
                vector<string> res;
                myBtree.rangeSearch(sSec, sId, eSec, eId, res);
                for (size_t k = 0; k < res.size(); k++) {
                    if (k) fputc('\t', rangeOut);
                    fputs(res[k].c_str(), rangeOut);
                }
                fputc('\n', rangeOut);
            }
            fclose(rangeIn);
            fclose(rangeOut);
            break;
        }
        case 'p':
        {
            /* print top-2 levels to [output file] */
            char *outputTextFile = argv[3];
            BTree myBtree(btreeBinaryFile);
            FILE *out = fopen(outputTextFile, "w");
            myBtree.print(out);
            fclose(out);
            break;
        }
    }
    return 0;
}

// Create BTree object & read header to initialize fields
BTree::BTree(const char *fileName) : fileName(fileName) {
    FILE *pFile = fopen(fileName, "rb");
    fseek(pFile, 0, SEEK_SET);
    fread(&blockSize, 4, 1, pFile);
    fread(&rootBID, 4, 1, pFile);
    fread(&depth, 4, 1, pFile);
    L = (blockSize - 4) / 12;
    fclose(pFile);
}

// Create BTree object & create binary file with header
BTree::BTree(const char *fileName, int blockSize) : fileName(fileName), blockSize(blockSize) {
    FILE *pFile = fopen(fileName, "wb");
    rootBID = 0;
    depth = 0;
    L = (blockSize - 4) / 12;
    fwrite(&blockSize, 4, 1, pFile);
    fwrite(&rootBID, 4, 1, pFile);
    fwrite(&depth, 4, 1, pFile);
    fclose(pFile);
}

// Return the physical offset for the given BID
int BTree::offset(int BID) {
    return 12 + (BID - 1) * blockSize;
}

// Return the BID for a newly allocated node
int BTree::allocBID() {
    FILE *pFile = fopen(fileName, "rb");
    fseek(pFile, 0, SEEK_END);
    int size = ftell(pFile);
    int BID = ((size - 12) / blockSize) + 1;
    fclose(pFile);
    return BID;
}

// Update the header
void BTree::writeHeader() {
    FILE *pFile = fopen(fileName, "r+b");
    fseek(pFile, 0, SEEK_SET);
    fwrite(&blockSize, 4, 1, pFile);
    fwrite(&rootBID, 4, 1, pFile);
    fwrite(&depth, 4, 1, pFile);
    fclose(pFile);
}

// Write a non-leaf node to the file
void BTree::writeNonLeaf(NonLeafNode &nonLeaf) {
    // Allocate buffer
    vector<char> buf(blockSize, 0);
    char *ptr = buf.data();

    // Write node data into the buffer
    memcpy(ptr, &nonLeaf.nextLevelBID, 4);
    ptr += 4;
    for (auto &entry : nonLeaf.entries) {
        memcpy(ptr, &entry, sizeof(IndexEntry));
        ptr += sizeof(IndexEntry);
    }

    // Overwrite the node's physical location with the buffer
    FILE *pFile = fopen(fileName, "r+b");
    fseek(pFile, offset(nonLeaf.BID), SEEK_SET);
    fwrite(buf.data(), 1, blockSize, pFile);
    fclose(pFile);
}

// Write a leaf node to the file
void BTree::writeLeaf(LeafNode &leaf) {
    // Allocate buffer
    vector<char> buf(blockSize, 0);
    char *ptr = buf.data();

    // Write node data into the buffer
    for (auto &entry : leaf.entries) {
        memcpy(ptr, &entry, sizeof(DataEntry));
        ptr += sizeof(DataEntry);
    }
    memcpy(buf.data() + blockSize - 4, &leaf.nextBID, 4);

    // Overwrite the node's physical location with the buffer
    FILE *pFile = fopen(fileName, "r+b");
    fseek(pFile, offset(leaf.BID), SEEK_SET);
    fwrite(buf.data(), 1, blockSize, pFile);
    fclose(pFile);
}

// Read the non-leaf node with the given BID from the file
NonLeafNode BTree::readNonLeaf(int BID) {
    NonLeafNode nonLeaf;
    nonLeaf.BID = BID;

    // Read the node from the file into the buffer
    vector<char> buf(blockSize);
    FILE *pFile = fopen(fileName, "rb");
    fseek(pFile, offset(BID), SEEK_SET);
    fread(buf.data(), 1, blockSize, pFile);
    fclose(pFile);

    // Deserialize buffer into the node object and return it
    char *ptr = buf.data();
    memcpy(&nonLeaf.nextLevelBID, ptr, 4);
    ptr += 4;
    for (int k = 0; k < L; k++) {
        IndexEntry entry;
        memcpy(&entry, ptr, sizeof(IndexEntry));
        if (entry.section == 0 && entry.id == 0) break;
        nonLeaf.entries.push_back(entry);
        ptr += sizeof(IndexEntry);
    }
    return nonLeaf;
}

// Read the leaf node with the given BID from the file
LeafNode BTree::readLeaf(int BID) {
    LeafNode leaf;
    leaf.BID = BID;

    // Read the node from the file into the buffer
    vector<char> buf(blockSize);
    FILE *pFile = fopen(fileName, "rb");
    fseek(pFile, offset(BID), SEEK_SET);
    fread(buf.data(), 1, blockSize, pFile);
    fclose(pFile);

    // Deserialize buffer into the node object and return it
    char *ptr = buf.data();
    for (int k = 0; k < L; k++) {
        DataEntry entry;
        memcpy(&entry, ptr, sizeof(DataEntry));
        if (entry.section == 0 && entry.id == 0) break;
        leaf.entries.push_back(entry);
        ptr += sizeof(DataEntry);
    }

    memcpy(&leaf.nextBID, buf.data() + blockSize - 4, 4);
    return leaf;
}

// Traverse from root using the search key to find the leaf node, recording the path
LeafNode BTree::findLeaf(int section, int id, vector<int>& path) {
    path.clear();
    int BID = rootBID;
    for (int level = 0; level < depth; level++) {
        NonLeafNode nonLeaf = readNonLeaf(BID);
        path.push_back(BID);
        int next = nonLeaf.nextLevelBID;
        for (auto &entry : nonLeaf.entries) {
            // Find the next BID
            if (cmpKey(section, id, entry.section, entry.id) >= 0) next = entry.BID;
            else break;
        }
        BID = next;
    }
    return readLeaf(BID);
}

// Insert a new entry into the leaf node
void BTree::insertIntoLeaf(LeafNode &leaf, const DataEntry &entry) {
    size_t pos = 0;
    // Find the sorted position and insert the entry
    while (pos < leaf.entries.size() && cmpKey(leaf.entries[pos].section, leaf.entries[pos].id, entry.section, entry.id) < 0)
        pos++;
    leaf.entries.insert(leaf.entries.begin() + pos, entry);
}

// Insert a new entry into the non-leaf node
void BTree::insertIntoNonLeaf(NonLeafNode &nonLeaf, const IndexEntry &entry) {
    size_t pos = 0;
    // Find the sorted position and insert the entry
    while (pos < nonLeaf.entries.size() && cmpKey(nonLeaf.entries[pos].section, nonLeaf.entries[pos].id, entry.section, entry.id) < 0)
        pos++;
    nonLeaf.entries.insert(nonLeaf.entries.begin() + pos, entry);
}

// Handle insertion into parent after a node split
void BTree::insertIntoParent(vector<int> &path, int leftBID, int upSection, int upId, int rightBID) {
    // Case: root node is split
    if (path.empty()) {
        int newRootBID = allocBID();
        NonLeafNode root;
        root.BID = newRootBID;
        root.nextLevelBID = leftBID;
        root.entries.push_back({upSection, upId, rightBID});
        writeNonLeaf(root);
        rootBID = newRootBID;
        depth += 1;
        writeHeader();
        return;
    }

    int parentBID = path.back();
    path.pop_back();
    NonLeafNode parent = readNonLeaf(parentBID);

    insertIntoNonLeaf(parent, {upSection, upId, rightBID});

    // If parent has space, write it as-is
    if ((int)parent.entries.size() <= L) {
        writeNonLeaf(parent);
        return;
    }

    // If parent has no space, split the parent as well
    int leftCount = L / 2;
    int midIndex = leftCount;
    int midSection = parent.entries[midIndex].section;
    int midId = parent.entries[midIndex].id;

    int newBID = allocBID();
    NonLeafNode right;
    right.BID = newBID;
    right.nextLevelBID = parent.entries[midIndex].BID;
    right.entries.assign(parent.entries.begin() + midIndex + 1, parent.entries.end());

    parent.entries.resize(leftCount);

    // Write the updated nodes after split
    writeNonLeaf(parent);
    writeNonLeaf(right);

    // Push the middle entry up to the parent
    insertIntoParent(path, parentBID, midSection, midId, newBID);
}

bool BTree::insert(int section, int id, int value) {
    // If the tree is empty, create the root node
    if (rootBID == 0) {
        int BID = allocBID();
        LeafNode leaf;
        leaf.BID = BID;
        leaf.nextBID = 0;
        leaf.entries.push_back({section, id, value});
        writeLeaf(leaf);
        rootBID = BID;
        depth = 0;
        writeHeader();
        return true;
    }

    // Find the leaf node and record the path
    vector<int> path;
    LeafNode leaf = findLeaf(section, id, path);

    insertIntoLeaf(leaf, {section, id, value});

    // If the node has space, write it as-is
    if ((int)leaf.entries.size() <= L) {
        writeLeaf(leaf);
        return true;
    }

    // If the node has no space, split it
    int total = (int)leaf.entries.size();
    int leftCount = (total + 1) / 2;
    int newBID = allocBID();

    LeafNode right;
    right.BID = newBID;
    right.entries.assign(leaf.entries.begin() + leftCount, leaf.entries.end());
    right.nextBID = leaf.nextBID;

    leaf.entries.resize(leftCount);
    leaf.nextBID = newBID;

    // Write the updated nodes after split
    writeLeaf(leaf);
    writeLeaf(right);

    // Copy the smallest key of the new node up to the parent
    int upSection = right.entries[0].section;
    int upId = right.entries[0].id;
    insertIntoParent(path, leaf.BID, upSection, upId, newBID);
    return true;
}

// Find and return the value for the search key, or -1 if not found
int BTree::search(int section, int id) {
    if (rootBID == 0) return -1;
    vector<int> path;
    LeafNode node = findLeaf(section, id, path);
    for (auto &entry : node.entries)
        if (cmpKey(section, id, entry.section, entry.id) == 0) return entry.value;
    return -1;
}

// Find and return all entries within the specified search key range
void BTree::rangeSearch(int sSec, int sId, int eSec, int eId, vector<string> &results) {
    results.clear();
    if (rootBID == 0) return;

    vector<int> path;
    LeafNode curLeaf = findLeaf(sSec, sId, path);

    bool done = false;
    while (!done) {
        for (auto &entry : curLeaf.entries) {
            if (cmpKey(entry.section, entry.id, sSec, sId) < 0) continue;
            if (cmpKey(entry.section, entry.id, eSec, eId) > 0) {
                done = true;
                break;
            }

            char line[64];
            snprintf(line, sizeof(line), "%d,%d,%d", entry.section, entry.id, entry.value);
            results.push_back(line);
        }
        if (done) break;
        // Continue sequential scan via next BID in leaf
        if (curLeaf.nextBID != 0) curLeaf = readLeaf(curLeaf.nextBID);
        else break;
    }
}

void BTree::print(FILE *out) {
    if (rootBID == 0) return;

    // Case: only the root node exists
    if (depth == 0) {
        LeafNode root = readLeaf(rootBID);
        fprintf(out, "<0>\n");
        for (size_t k = 0; k < root.entries.size(); k++) {
            if (k) fprintf(out, ", ");
            fprintf(out, "%d:%d", root.entries[k].section, root.entries[k].id);
        }
        fprintf(out, "\n");
        return;
    }

    NonLeafNode root = readNonLeaf(rootBID);
    fprintf(out, "<0>\n");
    for (size_t k = 0; k < root.entries.size(); k++) {
        if (k) fprintf(out, ", ");
        fprintf(out, "%d:%d", root.entries[k].section, root.entries[k].id);
    }
    fprintf(out, "\n");

    fprintf(out, "<1>\n");

    vector<int> children;
    children.push_back(root.nextLevelBID);
    for (auto &entry : root.entries)
        children.push_back(entry.BID);

    bool first = true;
    // Case: root's children are leaf nodes
    if (depth == 1) {
        for (int childBID : children) {
            LeafNode leaf = readLeaf(childBID);
            for (auto &entry : leaf.entries) {
                if (!first) fprintf(out, ", ");
                fprintf(out, "%d:%d", entry.section, entry.id);
                first = false;
            }
        }
    }
    // Case: root's children are non-leaf nodes
    else {
        for (int childBID : children) {
            NonLeafNode nonLeaf = readNonLeaf(childBID);
            for (auto &entry : nonLeaf.entries) {
                if (!first) fprintf(out, ", ");
                fprintf(out, "%d:%d", entry.section, entry.id);
                first = false;
            }
        }
    }
    fprintf(out, "\n");
}
