#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct Slot {
    int r, c, len;
    bool isVertical;
};

vector<Slot> slots;


/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */
 
 
// 1. Check if a word can fit (Length + Character Conflicts)
bool canPlace(const vector<string>& grid, const string& word, const Slot& slot) {
    if (word.length() != slot.len) return false;

    for (int k = 0; k < word.length(); k++) {
        int r = slot.r + (slot.isVertical ? k : 0);
        int c = slot.c + (slot.isVertical ? 0 : k);

        // Conflict if the cell is not empty AND doesn't match the word's char
        if (grid[r][c] != '-' && grid[r][c] != word[k]) {
            return false;
        }
    }
    return true;
}

// 2. Place the word and return a 'mask' of what we actually changed
vector<bool> placeWord(vector<string>& grid, const string& word, const Slot& slot) {
    vector<bool> placedMask(word.length(), false);
    
    for (int k = 0; k < word.length(); k++) {
        int r = slot.r + (slot.isVertical ? k : 0);
        int c = slot.c + (slot.isVertical ? 0 : k);

        // Only place (and mark true) if the cell was empty
        if (grid[r][c] == '-') {
            grid[r][c] = word[k];
            placedMask[k] = true;
        }
    }
    return placedMask;
}

// 3. Remove the word using the mask to only delete what we placed
void removeWord(vector<string>& grid, const Slot& slot, const vector<bool>& placedMask) {
    for (int k = 0; k < placedMask.size(); k++) {
        // If we placed it, we remove it. If it was already there, leave it alone.
        if (placedMask[k]) {
            int r = slot.r + (slot.isVertical ? k : 0);
            int c = slot.c + (slot.isVertical ? 0 : k);
            grid[r][c] = '-';
        }
    }
}
bool solve(int slotIndex ,vector<string>& grid, vector<Slot>& slots , vector<string>& words , vector<bool>& used){
    
    if (slotIndex==slots.size()) return true;
    
    for (int i = 0 ; i< words.size();i++){
        
        if (used[i]) continue;
        
        if (canPlace(grid , words[i] , slots[slotIndex] )){
            // 2. Place word and track exactly which cells changed
            vector<bool> placedMask = placeWord(grid, words[i], slots[slotIndex]);
            used[i] = true;

            // 3. Recurse
            if (solve(slotIndex + 1, grid, slots, words, used)) {
                return true;
            }

            // 4. Backtrack: Restore grid using the mask
            removeWord(grid, slots[slotIndex], placedMask);
            used[i] = false;
        }
    }
    
    return false;
}
vector<string> splitWords(string s) {
    vector<string> res;
    string temp = "";
    for (char c : s) {
        if (c == ';') {
            res.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    res.push_back(temp);
    return res;
}
vector<string> crosswordPuzzle(vector<string>& crossword, string words , vector<Slot>& slots) {
    
    vector<string> ws = splitWords(words);
    vector<bool> used(ws.size() , false);
    
    bool isSolved = solve(0, crossword, slots, ws, used);
    return crossword;
}

int main()
{

        ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }
    
        // Horizontal Scan
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (crossword[r][c] == '-') {
                int startC = c;
                while (c < 10 && crossword[r][c] == '-') {
                    c++;
                }
                int length = c - startC;
                if (length > 1) {
                    slots.push_back({r, startC, length, false});
                }
            }
        }
    }
    
    // Vertical Scan
    for (int c = 0; c < 10; c++) {
        for (int r = 0; r < 10; r++) {
            if (crossword[r][c] == '-') {
                int startR = r;
                while (r < 10 && crossword[r][c] == '-') {
                    r++;
                }
                int length = r - startR;
                if (length > 1) {
                    slots.push_back({startR, c, length, true});
                }
            }
        }
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words , slots);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
