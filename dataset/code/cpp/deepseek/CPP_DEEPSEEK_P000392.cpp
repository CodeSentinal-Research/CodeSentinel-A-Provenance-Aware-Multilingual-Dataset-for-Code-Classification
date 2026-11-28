Sure, here is a simple program using C++ that will search for files with a given extension.

#include <iostream>
#include <dirent.h>
#include <string>

using namespace std;

bool hasExtension(string filename, string extension) {
    size_t pos = filename.rfind(".");
    if (pos == string::npos) return false;
    string ext = filename.substr(pos + 1);
    return ext == extension;
}

int main(int argc, char* argv[]) {
    DIR *dir;
    struct dirent *ent;

    if (argc < 3) {
        cout << "Usage: ./program <directory> <extension>" << endl;
        return 1;
    }

    const char *dirname = argv[1];
    const char *extension = argv[2];

    if ((dir = opendir (dirname)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (!hasExtension(string(ent->d_name), string(extension)))
                continue;
            cout << ent->d_name << endl;
        }
        closedir (dir);
    } else {
        perror("Couldn't open this directory");
        return 1;
    }
    return 0;
}
This program uses the `dirent.h` library to read the directory contents, and uses a function `hasExtension` to check if a filename has the given extension. It then uses this function in the main function to print all files in the specified directory with the given extension.

You can compile and run this program using a command line like:
g++ program.cpp -o program
./program /path/to/directory extension
where `/path/to/directory` is the directory you want to search, and `extension` is the file extension you are looking for.

Please note that this program uses the POSIX `opendir`, `readdir`, `closedir` and `perror` functions. You may need to include the necessary headers and link against the necessary libraries.