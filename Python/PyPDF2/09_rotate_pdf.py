import os
from PyPDF2 import PdfReader, PdfWriter
import argparse

def rotate_pdf(pdf_path, page_num: int, rotation: int = 90):
    """
    Rotate a specific page of the given PDF file and save it as a new PDF.

    Args:
        pdf_path (str): Path to the input PDF file.
        page_num (int): Page number to be rotated (0-based index).
        rotation (int): Rotation angle in degrees (default: 90).

    The function reads the input PDF file using PyPDF2, rotates the specified page,
    and saves the rotated page as a new PDF file.
    """
    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)

        # Check if the provided page number is within the valid range
        if page_num < 0 or page_num >= len(reader.pages):
            print(f"Error: Invalid page number. The PDF has {len(reader.pages)} pages.")
            return

        # Create a new PDF writer to store the rotated page
        writer = PdfWriter()
        writer.add_page(reader.pages[page_num])

        # Rotate the specified page by the given rotation angle
        writer.pages[page_num-1].rotate(rotation)

        # Generate the output file name based on the input file name and the rotation angle
        filename = os.path.splitext(pdf_path)[0]
        output_filename = f"{filename}_page_{page_num}_rotated_{rotation}deg.pdf"

        # Save the rotated page to a new PDF file
        with open(output_filename, "wb") as out:
            writer.write(out)

        print(f"Page {page_num + 1} rotated {rotation} degrees and saved as {output_filename}.")

if __name__ == "__main__":
    # Set up the argument parser
    parser = argparse.ArgumentParser(
        usage='%(prog)s <PDF_Path> <Page_Number> [--rotation ROTATION]',
        description='A Simple Program to Rotate a Specific Page of a PDF'
    )

    # Add the PDF file path argument
    parser.add_argument('pdf_path', type=str, help='Path to the PDF file')

    # Add the page number argument
    parser.add_argument('page_number', type=int, help='Page number to be rotated (0-based index)')

    # Add the optional rotation angle argument with a default value of 90
    parser.add_argument('--rotation', type=int, default=90, help='Rotation angle in degrees (default: 90)')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the rotate_pdf() function with the provided arguments
    rotate_pdf(args.pdf_path, args.page_number, args.rotation)
