import os
from PyPDF2 import PdfMerger

def fetch_all_pdf_files(parent_folder: str):
    target_files = []
    for path, subdirs, files in os.walk(parent_folder):
        for name in files:
            if name.endswith(".pdf"):
                target_files.append(os.path.join(path, name))
                print(name)
    return target_files

def merge_pdf(list_of_pdfs,output_filename="final_merged_file.pdf"):
    merger = PdfMerger()
    with open(output_filename,"wb") as f:
        for file in list_of_pdfs:
            merger.append(file)
        merger.write(f)

pdf_list=fetch_all_pdf_files("./")
merge_pdf(pdf_list)
