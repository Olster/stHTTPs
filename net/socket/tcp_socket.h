#ifndef NET_SOCKET_TCP_SOCKET_H_
#define NET_SOCKET_TCP_SOCKET_H_

#include "net/socket/socket.h"

class TcpSocket : public Socket {
 public:
  TcpSocket() {}
  explicit TcpSocket(SOCK_TYPE socketFd);

  virtual ~TcpSocket();

  bool Open() override;

  // Send |sizeBytes| bytes of |data| and return bytes sent.
  int Send(const char* data, int sizeBytes);

  // Try to read |sizeBytes| bytes into |data| and return 
  // bytes actually read.
  int Receive(char* data, int maxSize);
};
#endif // NET_SOCKET_TCP_SOCKET_H_
