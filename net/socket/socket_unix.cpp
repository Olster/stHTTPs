#include "net/socket/socket.h"

#include <unistd.h>

Socket::~Socket() {
  ShutDown();
  Close();
}

bool Socket::Close() {
  return close(m_socket);
}

bool Socket::ShutDown(ShutDownCode code) {
  return shutdown(m_socket, code) != 0;
}
