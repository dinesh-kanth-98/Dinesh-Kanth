from PyPDF2 import PdfReader, PdfWriter
import argparse

def write_metadata_to_file(file_name, output_file, metadata):
    # Initialize the writer outside the try-except block
    writer = PdfWriter()
    try:
        # Read the PDF file using PdfReader
        reader = PdfReader(file_name)
    except FileNotFoundError:
        print(f"Error: File '{file_name}' not found.")
    except Exception as e:
        print(f"An error occurred while reading the PDF: {str(e)}")

    # Add all pages to the writer
    for page in reader.pages:
        writer.add_page(page)

    # Add the metadata using the add_metadata() method
    writer.add_metadata(metadata)

    # Save the new PDF to the output file
    with open(output_file, "wb") as f:
        writer.write(f)

if __name__ == "__main__":
    # Set up the argument parser
    parser = argparse.ArgumentParser(
        usage='%(prog)s <File_Name> <Output_File>',
        description='A Simple Program to Read and Write Pdf MetaData',
        epilog='This is additional information'
    )

    # Add the file and output_file arguments
    parser.add_argument('file', type=str, help='Path to the input file')
    parser.add_argument('output_file', type=str, help='Path to the output file')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Get metadata values from the user
    metadata = {}
    metadata["/Author"] = input("Enter Author: ")
    metadata["/Producer"] = input("Enter Producer: ")
    metadata["/Title"] = input("Enter Title: ")
    metadata["/Subject"] = input("Enter Subject: ")

    # Call the write_metadata_to_file() function with the file, output_file, and metadata arguments
    write_metadata_to_file(args.file, args.output_file, metadata)
