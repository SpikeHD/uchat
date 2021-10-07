all:
	cd ./src && \
	g++ client.cpp helpers.cpp alert.cpp -o ../build/uchat && \
	cd ../ && \
	make run

run:
	./build/uchat