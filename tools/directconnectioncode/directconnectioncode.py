import re
import socket
import struct


def parse_ip(ip: str) -> str:
    assert not re.search(
        "[^0123456789.]", ip), "Unsupported character found in IP address"

    octets = ip.split('.')
    assert len(octets) == 4, "IP address has unexpected octets: accepts x.x.x.x"

    for i, j in enumerate(octets):
        j = int(j)
        assert j >= 0 and j < 256, f"IP address octet {i + 1} exceeds expected range: 0 - 255"

    ip = socket.inet_aton(ip)
    return ip


def generate(ip: str, port: int, passcode: int):
    assert port >= 1024 and port < 65536, "Port exceeds accepted range: 1024 - 65535"
    assert passcode >= 0 and passcode < 2048, "Passcode exceeds accepted range: 0 - 2047"

    ip = parse_ip(ip)
    port = struct.pack(">H", port)
    passcode = struct.pack(">H", passcode)

    hex_code = passcode + port + ip
    direct_code = str(struct.unpack(">Q", hex_code)[0] + 0x3ed5142afa4755f)

    direct_code = direct_code[:6] + '-' + \
        direct_code[6:12] + '-' + direct_code[-6:]

    print("Your direct connection code is \"" + direct_code + "\".")
    print("Please have other clients use this code to connect to your server.")


if __name__ == '__main__':
    # Prompt the user to input their own IP, port, and passcode
    ip = input("Enter the IP address for the server: ")
    port = int(input("Enter the port number for the server: "))
    passcode = int(input("Enter the passcode for the server: "))

    generate(ip, port, passcode)
