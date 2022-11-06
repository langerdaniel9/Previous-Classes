import socket

valid = True


def start():
    global valid
    while valid:
        addrlst = []
        addr = input("Enter the website of which you want to find the DNS. Type done when done.\n").lower()
        if addr == 'stop':
            valid = False
            break
        addrlst.append(socket.gethostbyname(addr))
        print(addrlst)


start()
