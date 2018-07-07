//

import socket
//check port listening on windows
//open cmd as admin
//netstat -a -b

s = socket.socket()

s.bind(('0.0.0.0', 8090 ))
//binding to 0.0.0.0 allows connection from any ip addresss
//second number is port number.
s.listen(0)

while True:

    client, addr = s.accept()

    while True:
        content = client.recv(32)

        if len(content) ==0:
           break

        else:
            print(content)

    print("Closing connection")
    client.close()
