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

    print("Waiting for peer to connect")
    (client, addr) = server.accept()
    print("Peer connected!")
    client.send("Peer connected!".encode())

    while True:
        server_msg = input('>>> ')
        if server_msg == '.exit':
            break
        client.send(server_msg[:100].encode())
        client_msg = client.recv(100).decode()
        print(client_msg)

    socket.close()

if MODE == 'client':
    socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.connect(('localhost', 42069))

    print("Waiting for peer to connect")
    server_msg = socket.recv(100).decode()
    print(server_msg)

    while True:
        client_msg = input('>>> ')
        if client_msg == '.exit':
            break
        socket.send(client_msg[:100].encode())
        server_msg = socket.recv(100).decode()
        print(server_msg)

    socket.close()
