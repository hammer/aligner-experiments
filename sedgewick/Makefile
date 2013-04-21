BinarySearchTreeSTclient: Item.o BinarySearchTreeST.o
	g++ -dynamiclib -o libST.dylib -fPIC Item.o BinarySearchTreeST.o
	g++ -o STclient STclient.cpp -L. -lST

OrderedArraySTwithBinarySearchclient: Item.o OrderedArraySTwithBinarySearch.o
	g++ -dynamiclib -o libST.dylib -fPIC Item.o OrderedArraySTwithBinarySearch.o
	g++ -o STclient STclient.cpp -L. -lST

OrderedArraySTclient: Item.o OrderedArrayST.o
	g++ -dynamiclib -o libST.dylib -fPIC Item.o OrderedArrayST.o
	g++ -o STclient STclient.cpp -L. -lST

KeyIndexedArraySTclient: Item.o KeyIndexedArrayST.o
	g++ -dynamiclib -o libST.dylib -fPIC Item.o KeyIndexedArrayST.o
	g++ -o STclient STclient.cpp -L. -lST

BinarySearchTreeST.o: BinarySearchTreeST.cpp
	g++ -c -fPIC BinarySearchTreeST.cpp

OrderedArraySTwithBinarySearch.o: OrderedArraySTwithBinarySearch.cpp
	g++ -c -fPIC OrderedArraySTwithBinarySearch.cpp

OrderedArrayST.o: OrderedArrayST.cpp
	g++ -c -fPIC OrderedArrayST.cpp

KeyIndexedArrayST.o: KeyIndexedArrayST.cpp
	g++ -c -fPIC KeyIndexedArrayST.cpp

Item.o: Item.cpp
	g++ -c -fPIC Item.cpp

clean:
	rm -f STclient *.o *.a *.dylib *.so *~ \#*
