all:
	cd ./src && \
	g++ client.cpp helpers.cpp -o ../build/uchat && \
	cd ../ && \
	make run

run:
	./build/uchat