import socket
import select

HEADER_LENGTH = 10
IP = '0.0.0.0'
PORT = 42069


def wrap(messages):
    "Creates binary for a set of messages"
    payload = b''
    for msg in messages:
        payload += f'{len(msg):<{HEADER_LENGTH}}'.encode()
        payload += msg
    return payload

def receive_messages(client_socket):
    "Handles new messages from client"
    try:
        message_header = client_socket.recv(HEADER_LENGTH)

        if not len(message_header):
            return False # Client exited gracefully

        message_length = int(message_header.decode().strip())
        message_data = client_socket.recv(message_length)
        
        return {'header': message_length, 'data': message_data}
    
    except:
        return False


# Main
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((IP, PORT))
server_socket.listen()

sockets_list = [server_socket]
clients = {}

print(f'Listening for connections on {IP}:{PORT}...')
while True:
    read_sockets, _, exception_sockets = select.select(sockets_list, [], sockets_list)
    
    for notified_socket in read_sockets:
        if notified_socket == server_socket:
            # Accept new connection
            client_socket, client_address = server_socket.accept()
            user = receive_messages(client_socket)
            if user is False:
                continue
            
            sockets_list.append(client_socket)
            clients[client_socket] = user
            
            ip, port = client_address
            username = user['data'].decode()
            print(f'Accepted new connection from {ip}:{port}, username: {username}')
        else:
            message = receive_messages(notified_socket)
            
            if message is False:
                client = clients[notified_socket]['data'].decode()
                print(f'Closed connection from {client}')
                sockets_list.remove(notified_socket)
                del clients[notified_socket]
                continue

            user = clients[notified_socket]
            print(f'Received message from user {user["data"].decode()}')
            payload = wrap([user['data'], message['data']])
            for client_socket in clients:
                if client_socket != notified_socket:
                    client_socket.send(payload)

    for notified_socket in exception_sockets:
        sockets_list.remove(notified_socket)
        del clients[notified_socket]
            

