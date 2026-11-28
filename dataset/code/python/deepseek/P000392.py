def search_files_by_extension(file_names, extension):
    matching_files = [file for file in file_names if file.endswith(extension)]
    return matching_files


def main():
    file_names = input().split()
    extension = input()
    matching_files = search_files_by_extension(file_names, extension)
    for file in matching_files:
        print(file)


if __name__ == "__main__":
    main()