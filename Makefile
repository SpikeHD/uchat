all:
	cd ./src && \
	g++ client.cpp helpers.cpp alert.cpp chat_commands.cpp config.cpp -o ../build/uchat && \
	cd ../ && \
	make run

run:
	./build/uchat