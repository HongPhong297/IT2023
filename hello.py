import qrcode
from PIL import Image

# Load the image
image_path = 't1.jpg'
image = Image.open(image_path)

# Convert the image to grayscale
image = image.convert('L')

# Create a QR code instance
qr = qrcode.QRCode(
    version=None,  # Let qrcode determine the version
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)

# Add the image data to the QR code
qr.add_data(image.tobytes())

# Make the QR code
qr.make(fit=True)

# Get the actual version used
version = qr.version

# Update the version if it exceeds the valid range
if version > 40:
    qr.version = 40

# Generate the QR code
qr.make()

# Create an image from the QR code
qr_image = qr.make_image(fill_color="black", back_color="white")

# Save the QR code image
output_path = 'path_to_output_qr_code.png'
qr_image.save(output_path)
