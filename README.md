# Pebble vcard

This app is intended to show a QR code containing vcard information on the Pebble display. If you want to give someone your contact details he can just scan the QR code with his mobile phone and you don't even have to take yours out of the pocket.

The Pebble watch has a resolution of 144x168px, so keep the size small when you create a QR code with your own data. I created my QR code at http://www.qrcode-monkey.com/#vcard with a resolution of 2 pixel/QR-point, this generates a 130x130px sized image which fits perfectly on the Pebble display.

To create an app clone the repository, replace the qrcode.png file in the `resources/src/images/` directory with your own and build it with `./waf build`.