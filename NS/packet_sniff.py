import socket
import struct
from binascii import hexlify as hx

def mac(addr):
    b = ""
    for i in addr:
        b += "%.2x:" % i
    return b[:-1]

def ip(addr):
    b = ""
    for i in addr:
        b += "%.2d:" % i
    return b[:-1]

s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_TCP)

print("listening for packets...")
while True:
    packet = s.recvfrom(65565)
    
    print("----PACKET RECEIVED----")

    eth_header = packet[0][0:14]
    eth_header = struct.unpack("!6s6sH", eth_header)
    print("Ethernet Header")
    print(f"> Destination MAC: {mac(eth_header[0])}")
    print(f"> Source MAC: {mac(eth_header[1])}")
    print(f"> Protocol: {eth_header[2]}\n")

    ip_header = packet[0][14:34]
    ip_header = struct.unpack("!BBHHHBBH4s4s", ip_header)
    print("IP Header")
    print(f"> Version: {ip_header[0]}")
    print(f"> ToS: {ip_header[1]}")
    print(f"> Total Length: {ip_header[2]}")
    print(f"> Identification: {ip_header[3]}")
    print(f"> Fragment: {ip_header[4]}")
    print(f"> TTL: {ip_header[5]}")
    print(f"> Protocol: {ip_header[6]}")
    print(f"> Header Checksum: {ip_header[7]}")
    print(f"> Source IP: {ip(ip_header[8])}")
    print(f"> Destination IP: {ip(ip_header[9])}\n")

    tcp_header = packet[0][34:54]
    if len(tcp_header) == 20:
        tcp_header = struct.unpack("!HHLLBBHHH", tcp_header)
        print("TCP Header")
        print(f"> Source Port: {tcp_header[0]}")
        print(f"> Destination Port: {tcp_header[1]}")
        print(f"> Sequence Number: {tcp_header[2]}")
        print(f"> Acknowledge Number: {tcp_header[3]}")
        print(f"> Offset & Reserved: {tcp_header[4]}")
        print(f"> TCP Flag: {tcp_header[5]}")
        print(f"> Window: {tcp_header[6]}")
        print(f"> Checksum: {tcp_header[7]}")
        print(f"> Urgent Pointer: {tcp_header[8]}\n")
