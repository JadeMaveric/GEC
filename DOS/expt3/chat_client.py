import socket
import select
import errno

HEADER_LENGTH = 10
IP = 'localhost'
PORT = 42069


client_username = input("Username: ")
username = client_username.encode()
username_header = f"{len(username):<{HEADER_LENGTH}}".encode()

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((IP, PORT))
client_socket.setblocking(False)

client_socket.send(username_header + username)

while True:
    #TODO: This is blocking code, it should be moved into it's own thread 
    message = input(f'{client_username} > ')
    
    if message:
        message = message.encode()
        message_header = f"{len(message):<{HEADER_LENGTH}}".encode()
        client_socket.send(message_header + message)

    try:
        while True:
            username_header = client_socket.recv(HEADER_LENGTH)
            if not len(username_header):
                print("! Connection closed by server !")
                sys.exit()

            username_length = int(username_header.decode().strip())
            username = client_socket.recv(username_length).decode()
            
            message_header = client_socket.recv(HEADER_LENGTH)
            message_length = int(message_header.decode().strip())
            message = client_socket.recv(message_length).decode()

            print(f"{username} > {message}")
    except IOError as e:
        if e.errno != errno.EAGAIN and e.errno != errno.EWOULDBLOCK:
            print(f'Reading error: {str(e)}')
            sys.exit()
        continue
    except Exception as e:
        print(f'Reading error: {str(e)}')
        sys.exit()

