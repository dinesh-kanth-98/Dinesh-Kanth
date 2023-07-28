from PyPDF2 import PdfReader
import sys

# A function to retrieve PDF metadata
def get_pdf_metadata(pdf_path):
    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)
        info = reader.metadata
    return info

def main(file_name):
    """
    Main function that prints the file name and PDF metadata.
    """
    print("File name:", file_name)
    metadata = get_pdf_metadata(file_name)
    print("PDF Metadata:")
    print(metadata)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <file_name>")
    else:
        file_name = sys.argv[1]
        main(file_name)
