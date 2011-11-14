BUILD_DIR=build

echo -n "Cleaning..."
if [ -d $BUILD_DIR ]; then
    cd $BUILD_DIR
    rm *.lst
    rm *.hex
    rm *.cod
    rm *.asm
    rm *.o
fi
echo "done."



