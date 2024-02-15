# tag_gateway
Currently supports transferring decoded QR code information from a client to the gateway.
The tag_gateway serves a static file wrapping [Vue QR code reader](https://vue-qrcode-reader.netlify.app/demos/Simple.html).
A WebSocket connection is then established, over which the client sends the decoded QR code text strings.

## Installation instructions: 
In the repo root execute the build script to build the binary.
``` ./build.sh ```

Input the sudo password to install the required files as well as the binary

## Running
If you have /usr/local/bin in your path, simply run
```tag_gateway```
otherwise, run the ```./tag_gateway``` binary in the ```build``` directory.


## Using with a client
It is now possible to go to the server IP with any browser to use the tag_gateway. 
Remember to accept the self-signed certificate on the client browser.
Correct behavior can be validated by pointing the client camera at a QR code generated at the website [qr.io](https://qr.io/).
