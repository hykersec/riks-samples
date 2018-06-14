 #!/bin/sh

mkdir -p build
cd build

cp ../../../../riks-swift/build/Riks.Swiftmodule .
cp ../../../../riks-swift/build/libRiks.dylib .
cp ../../../../riks-swift/build/lib/libriks-objc.dylib .

swiftc \
    -emit-executable \
    ../src/main.swift \
    ../src/RiksMQTTClient.swift \
    -I. \
    -L. \
    -lRiks \
    -Xlinker -rpath \
    -Xlinker .

./main