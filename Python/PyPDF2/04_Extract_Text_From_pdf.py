from PyPDF2 import PdfReader
import argparse

def extract_text_from_pdf(pdf_path):
    """
    Extract text from each page of the given PDF file and print it to the console.

    Args:
        pdf_path (str): Path to the input PDF file.
    """
    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)
        results = []
        for i in range(0, len(reader.pages)):
            selected_page = reader.pages[i]
            text = selected_page.extract_text()
            results.append(text)
            print(f"Page {i + 1} Text:")
            print(text)
        # return ' '.join(results) # convert list to a single document

if __name__ == "__main__":
    # Set up the argument parser
    parser = argparse.ArgumentParser(
        usage='%(prog)s <PDF_Path>',
        description='A Simple Program to Extract Text From PDF',
        epilog='This is additional information'
    )

    # Add the pdf_path argument
    parser.add_argument('pdf_path', type=str, help='Path to the PDF file')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the extract_text_from_pdf() function with the pdf_path argument
    extract_text_from_pdf(args.pdf_path)
