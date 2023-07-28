import os
from PyPDF2 import PdfReader
import argparse

def extract_images_from_pdf(pdf_path):
    # Create a folder with the PDF filename to store the images
    folder_name = os.path.splitext(os.path.basename(pdf_path))[0]
    os.makedirs(folder_name, exist_ok=True)

    with open(pdf_path, "rb") as f:
        reader = PdfReader(f)
        for page_num in range(0, len(reader.pages)):
            selected_page = reader.pages[page_num]
            for img_file_obj in selected_page.images:
                # Generate the image filename based on the image name and the page number
                img_filename = os.path.join(folder_name, f"page_{page_num + 1}_{img_file_obj.name}")
                with open(img_filename, "wb") as out:
                    out.write(img_file_obj.data)

if __name__ == "__main__":
    # Create an argument parser
    # %(prog)s gives the file name
    parser = argparse.ArgumentParser(
        usage='%(prog)s <File_Path>',
        description='A Program to Extract Images from a PDF'
    )

    # Add the file_path argument
    parser.add_argument('file_path', type=str, help='Path to the PDF file')

    args = parser.parse_args()

    extract_images_from_pdf(args.file_path)
