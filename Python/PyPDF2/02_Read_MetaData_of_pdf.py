from PyPDF2 import PdfReader
import argparse
import colorama
from colorama import Fore as FG, Back as BG, Style as SL

def main(file_name):
    # Read the PDF file using PyPDF2
    try:
        reader = PdfReader(file_name)
    except FileNotFoundError:
        print(f"Error: File '{file_name}' not found.")
        exit()
    except Exception as e:
        print(f"An error occurred while reading the PDF: {str(e)}")
        exit()

    # Get the metadata from the PDF
    meta = reader.metadata

    # Print the number of pages in the PDF
    print(f"{SL.BRIGHT}Number of Pages: {FG.GREEN}{len(reader.pages)}\n")

    # Print the PDF metadata if available
    print(f"{FG.YELLOW}{SL.BRIGHT}PDF Metadata:")
    print(f"{FG.CYAN}{SL.BRIGHT}Title: {FG.MAGENTA}{SL.BRIGHT}{meta.title}")
    print(f"{FG.CYAN}{SL.BRIGHT}Author: {FG.MAGENTA}{SL.BRIGHT}{meta.author}")
    print(f"{FG.CYAN}{SL.BRIGHT}Subject: {FG.MAGENTA}{SL.BRIGHT}{meta.subject}")
    print(f"{FG.CYAN}{SL.BRIGHT}Producer: {FG.MAGENTA}{SL.BRIGHT}{meta.producer}")


if __name__ == "__main__":
    # Create an argument parser
    # %(prog)s gives the file name
    parser = argparse.ArgumentParser(
        usage='%(prog)s <File_Name>',
        description='A Simple Program to Read Pdf MetaData'
    )

    # Add the file_path argument
    parser.add_argument('file_path', type=str, help='Path to the PDF file')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Initialize colorama
    colorama.init(autoreset=True)

    # Call the main function with the file argument
    main(args.file_path)
