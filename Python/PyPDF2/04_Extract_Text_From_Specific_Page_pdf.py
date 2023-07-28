from PyPDF2 import PdfReader
import argparse

def read_text_from_page(pdf_path, page_number):
    """
    Read text from the specified page number of the given PDF file.

    Args:
        pdf_path (str): Path to the input PDF file.
        page_number (int): Page number from which to read the text.
    """
    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)

        # Check if the provided page number is valid
        if page_number < 1 or page_number > len(reader.pages):
            print(f"Error: Invalid page number. The PDF has {len(reader.pages)} pages.")
            return

        selected_page = reader.pages[page_number - 1]
        text = selected_page.extract_text()
        print(f"Text from Page {page_number}:")
        print(text)

if __name__ == "__main__":
    # Set up the argument parser
    parser = argparse.ArgumentParser(
        usage='%(prog)s <PDF_Path> <Page_Number>',
        description='A Simple Program to Read Text From a Specific Page of a PDF',
        epilog='This is additional information'
    )

    # Add the pdf_path and page_number arguments
    parser.add_argument('pdf_path', type=str, help='Path to the PDF file')
    parser.add_argument('page_number', type=int, help='Page number from which to read the text')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the read_text_from_page() function with the pdf_path and page_number arguments
    read_text_from_page(args.pdf_path, args.page_number)
