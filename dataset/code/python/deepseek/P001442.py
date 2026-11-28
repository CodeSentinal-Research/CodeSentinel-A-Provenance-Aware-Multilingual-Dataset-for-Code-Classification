Here's the Python code for the given problem:

def find_duplicate_files():
    N = int(input().strip())

    file_dict = {}

    for _ in range(N):
        file_info = input().strip().split(' ')
        file_path = file_info[0]
        file_content = ' '.join(file_info[1:])

        if file_content in file_dict:
            file_dict[file_content].append(file_path)
        else:
            file_dict[file_content] = [file_path]

    for content, paths in file_dict.items():
        if len(paths) > 1:
            print(content)
            for path in paths:
                print(path)

if __name__ == "__main__":
    find_duplicate_files()

In this code, we first get the number of files and then read each file path and its content. We then check if the content of the file exists in the dictionary. If it does, we add the file path to the list of paths associated with the content. If it doesn't, we create a new list for the content and add the file path to it.

Finally, we print each content (i.e., each file path) if there is more than one associated file path.