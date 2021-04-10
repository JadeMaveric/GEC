#!/bin/python
import sys
import socket

# Check if we're running in an interactive shell
if __name__ == '__main__':
    if 'client' in sys.argv:
        MODE = 'client'
    else:
        MODE = 'server'
else:
    # Clients can only talk in an interactive shell
    MODE = 'server'

if MODE == 'server':
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server.bind(('localhost', 42069))
    server.listen()

    print("Entering Server loop")
    while True:
        (client, addr) = server.accept()
        client.send("Hello! You've connected to the server".encode())
        response = client.recv(100).decode()
        print(f'Response ({addr}) - {response}\n')

if MODE == 'client':
    socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.connect(('localhost', 42069))

    server_msg = socket.recv(100).decode()
    print(server_msg)
    client_msg = input('>>> ')
    socket.send(client_msg[:100].encode())
    socket.close()
