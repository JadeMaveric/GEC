import socket
import select
import errno
import sys
import tty
import termios

HEADER_LENGTH = 10
IP = input("Server addr: ").strip()
PORT = int(input("Server port: ").strip())

def userInputPresent():
    return select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])

old_terminal_settings = termios.tcgetattr(sys.stdin)

try:
    client_username = input("Username: ")
    username = client_username.encode()
    username_header = f"{len(username):<{HEADER_LENGTH}}".encode()

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((IP, PORT))
    client_socket.setblocking(False)
    
    print("Connected to server!")
    client_socket.send(username_header + username)

    while True:
        if userInputPresent():
            message = sys.stdin.readline()[:-1]
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
                filetext = client_socket.recv(message_length).decode()
                filename = message.decode()
                
                if filetext[:3] != '404':
                    view_prompt = input(f'Received {filename}, would you like to view it\'s contents? [Y/n]: ')
                    if view_prompt != 'n':
                        print(f"{filetext}")
                    save_prompt = input('Would you like to save the file? [Y/n]: ')
                    if save_prompt != 'n':
                        file = open(filename, 'w')
                        file.writelines(filetext)
                        file.close()
                else:
                    print(f"{filetext}")

        except IOError as e:
            if e.errno != errno.EAGAIN and e.errno != errno.EWOULDBLOCK:
                print(f'Reading error: {str(e)}')
                termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_terminal_settings)
                sys.exit()
            continue
        except Exception as e:
            print(f'Reading error: {str(e)}')
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_terminal_settings)
            sys.exit()
finally:
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_terminal_settings)
