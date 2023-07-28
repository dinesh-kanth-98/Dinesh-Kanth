import os
from PIL import Image
import argparse

def convert_img2pdf(image_files):
    for image_file in image_files:
        my_image = Image.open(image_file)
        img = my_image.convert("RGB")
        filename = f"{os.path.splitext(image_file)[0]}.pdf"
        img.save(filename)
        print(f"Image {image_file} converted to PDF and saved as {filename}")

if __name__ == "__main__":
    # Create an argument parser
    parser = argparse.ArgumentParser(
        usage='%(prog)s <Image_Files...>',
        description='A Program to Convert Images to PDF'
    )

    # Add the image_files argument
    parser.add_argument('image_files', type=str, nargs='+', help='Path(s) to the image file(s)')

    args = parser.parse_args()

    convert_img2pdf(args.image_files)
