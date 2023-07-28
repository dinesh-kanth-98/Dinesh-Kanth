import os
from PyPDF2 import PdfReader, PdfWriter
import argparse

# Function to Split PDF into a Specific Range of Pages
def get_pdf_upto(pdf_path, start_page:int=0, stop_page: int = 0):
    """
    Extract a specific range of pages from the given PDF file and save them in a new PDF.

    Args:
        pdf_path (str): Path to the input PDF file.
        start_page (int): Start page number (inclusive).
        stop_page (int): Stop page number (exclusive).

    The function reads the input PDF file using PyPDF2 and extracts the pages within the specified range.
    The extracted pages are saved in a new PDF file with the format: [original_filename]_from_[start_page]_to_[stop_page - 1].pdf
    """
    # Read the PDF file using PyPDF2
    try:
        reader = PdfReader(pdf_path)
    except FileNotFoundError:
        print(f"Error: File '{pdf_path}' not found.")
        exit()
    except Exception as e:
        print(f"An error occurred while reading the PDF: {str(e)}")
        exit()

    # Check if the start_page is greater than or equal to the stop_page
    if start_page >= stop_page:
        print("Error: Start page should be less than the stop page.")
        exit()

    # Check if the provided page numbers are within the valid range
    if start_page <= 0 or stop_page > len(reader.pages):
        print(f"Error: Invalid page range. The PDF has {len(reader.pages)} pages.")
        exit()

    # Create a new PDF writer to store the extracted pages
    writer = PdfWriter()
    for page_num in range(start_page, stop_page):
        selected_page = reader.pages[page_num - 1]
        writer.add_page(selected_page)

    # Generate the output file name based on the input file name and the range of pages extracted
    filename = os.path.splitext(pdf_path)[0]
    output_filename = f"{filename}_from_{start_page}_to_{stop_page - 1}.pdf"

    # Save the extracted pages to a new PDF file
    with open(output_filename, "wb") as out:
        writer.write(out)

def main(file_name, start_page, stop_page):
    """
    Main function to split the PDF file into a specific range of pages.

    Args:
        file_name (str): Path to the input PDF file.
        start_page (int): Start page number (inclusive).
        stop_page (int): Stop page number (exclusive).
    """
    get_pdf_upto(file_name, start_page, stop_page)

def positive_int(value):
    """
    Custom argument type to ensure the value is a positive integer.

    Args:
        value (str): The value provided as the command-line argument.

    Returns:
        int: The converted positive integer value.

    Raises:
        argparse.ArgumentTypeError: If the value is not a positive integer.
    """
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError("%s is not a positive integer" % value)
    return ivalue

if __name__ == "__main__":
    # Create an argument parser
    # %(prog)s gives the file name
    parser = argparse.ArgumentParser(
        usage='%(prog)s <File_Path> <Start_Page> <End_Page>',
        description='A Simple Program to Extract a Specific Range of Pages from a PDF'
    )

    # Add the file_path argument
    parser.add_argument('file_path', type=str, help='Path to the PDF file')

    # Add an argument with the positive_int function as the type parameter
    parser.add_argument('start_page', type=positive_int,
                    help='Start page number should be greater than 0')

    # Add an argument with the positive_int function as the type parameter
    parser.add_argument('stop_page', type=positive_int,
                    help='Stop page number should be greater than 0')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the main function with the file argument
    main(args.file_path, args.start_page, args.stop_page + 1)
