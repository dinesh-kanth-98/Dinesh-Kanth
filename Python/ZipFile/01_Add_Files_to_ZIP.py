import argparse
import zipfile
import os


def add_files_to_zip(file_list, zip_filename):
    with zipfile.ZipFile(zip_filename, 'w') as zip_file:
        for file_name in file_list:
            # Check if the file exists before adding it to the ZIP archive
            if os.path.exists(file_name):
                zip_file.write(file_name)
                print(f"{file_name} added to {zip_filename}.")
            else:
                print(f"{file_name} not found. Skipped.")


def main():
    # Create an argument parser
    parser = argparse.ArgumentParser(description='Add files to a ZIP archive.')
    parser.add_argument('files', nargs='+', type=str,
                        help='File names to add to the ZIP archive.')
    parser.add_argument('zip_filename', type=str,
                        help='Name of the output ZIP archive.')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Get the list of file names and the output ZIP archive name from the arguments
    file_list = args.files
    zip_filename = args.zip_filename

    # Call the function to add files to the ZIP archive
    add_files_to_zip(file_list, zip_filename)


if __name__ == "__main__":
    main()
