mkdir -p ssl
openssl req  -nodes -new -x509  -keyout server.key -out server.cert  -subj "/C=GB/ST=London/L=London/O=Global Security/OU=IT Department/CN=example.com"
mv server.cert ssl/
mv server.key ssl/

mkdir -p build
cd build
cmake ..
make
sudo make install