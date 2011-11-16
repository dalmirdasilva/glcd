INCLUDES="-I/home/dalmir/Dropbox/Microcontrollers/picnix/ \
          -I/home/dalmir/storage/github/pic/sdcc/driver/graphic/lcd/ \
          -I/home/dalmir/storage/github/pic/sdcc/library/graphic/lcd/ \
          -I/home/dalmir/storage/github/pic/sdcc/driver/graphic/glcd/ \
          -I/home/dalmir/storage/github/pic/sdcc/library/graphic/glcd/ \
          -I/home/dalmir/storage/github/pic/sdcc/include/ "
BUILD_DIR=build
TARGET=main
ARCH=-mpic16
CHIP=-p18f4550

echo "Making..."

if [ ! -d $BUILD_DIR ]; then
    mkdir $BUILD_DIR
fi

rm $BUILD_DIR/*.c
rm $BUILD_DIR/*.h
cp *.c $BUILD_DIR
cp *.h $BUILD_DIR

cd $BUILD_DIR
echo "Entering in the build dir (${BUILD_DIR})"

echo -n "Compiling..."
sdcc --opt-code-size $TARGET.c $INCLUDES $ARCH $CHIP

echo "ok."

cp $TARGET.hex ..

cd ..
echo "Exiting the build dir (${BUILD_DIR})"

echo "done."

