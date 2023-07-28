import os
from PyPDF2 import PdfReader, PdfWriter
import sys

def split_pdf(pdf_path):
    """
    Split the input PDF into multiple PDF pages.
    Each page is saved as a separate PDF file.

    Args:
        pdf_path (str): Path to the input PDF file.
    """
    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)
        
        # Loop through pages
        for page_num in range(len(reader.pages)):
            selected_page = reader.pages[page_num]
            
            # Create a new writer
            writer = PdfWriter()
            writer.add_page(selected_page)  # Add the selected page to the writer
            
            # Generate output file name
            filename = os.path.splitext(pdf_path)[0]
            output_filename = f"{filename}_page_{page_num + 1}.pdf"
            
            # Save and compile the PDF
            with open(output_filename, "wb") as out:
                writer.write(out)
                
            print(f"Created PDF: {output_filename}")

def main(file_name):
    """
    Main function to split the PDF file into multiple pages.

    Args:
        file_name (str): Path to the input PDF file.
    """
    split_pdf(file_name)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <file_name>")
    else:
        file_name = sys.argv[1]
        main(file_name)
