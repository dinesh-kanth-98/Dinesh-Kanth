import argparse
import zipfile
import os

def extract_zip_to_folder(zip_filename, target_folder):
    with zipfile.ZipFile(zip_filename, 'r') as zip_file:
        # Create the target folder if it doesn't exist
        os.makedirs(target_folder, exist_ok=True)
        # Extract all files from the ZIP archive to the target folder
        zip_file.extractall(path=target_folder)
        print(f"{zip_filename} has been extracted to {target_folder}.")

def main():
    # Create an argument parser
    parser = argparse.ArgumentParser(description='Extract a ZIP archive to a specific folder.')
    parser.add_argument('zip_file', type=str, help='ZIP archive to extract.')
    parser.add_argument('target_folder', type=str, help='Target folder to extract files to.')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Get the ZIP archive name and the target folder from the arguments
    zip_filename = args.zip_file
    target_folder = args.target_folder

    # Call the function to extract the ZIP archive to the target folder
    extract_zip_to_folder(zip_filename, target_folder)

if __name__ == "__main__":
    main()
