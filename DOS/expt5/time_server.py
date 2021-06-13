#!/bin/python
import sys
import select
import socket
import time

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

    server.bind(('localhost', 4200))
    server.listen()

    print("Entering Server loop")
    while True:
        (client, addr) = server.accept()
        response = client.recv(100).decode()
        client.send(str(time.clock_gettime(0)).encode())
        print(f'Response ({addr}) - {response}\n')

if MODE == 'client':
    socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.connect(('localhost', 4200))

    while True:
        client_msg = input('>>> ')
        socket.send(client_msg[:100].encode())
        server_msg = socket.recv(100).decode()
        print(server_msg)
    socket.close()
