import argparse
import shutil

def create_zip_from_source(source_path, zip_filename):
    shutil.make_archive(zip_filename, 'zip', source_path)
    print(f"ZIP archive {zip_filename}.zip created from {source_path}.")

def main():
    # Create an argument parser
    parser = argparse.ArgumentParser(description='Create a ZIP archive from a source directory.')
    parser.add_argument('source_directory', type=str, help='Source directory to create the ZIP archive from.')
    parser.add_argument('zip_filename', type=str, help='Name of the output ZIP archive.')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Get the source directory and the output ZIP archive name from the arguments
    source_directory = args.source_directory
    zip_filename = args.zip_filename

    # Call the function to create the ZIP archive
    create_zip_from_source(source_directory, zip_filename)

if __name__ == "__main__":
    main()
