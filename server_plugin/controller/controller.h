#ifndef SERVER_PLUGIN_CONTROLLER_CONTROLLER_H_
#define SERVER_PLUGIN_CONTROLLER_CONTROLLER_H_

#include <list>
#include <string>

#include "server_plugin/server_plugin.h"

class Server;

// Controller plugin is built-in inside of the server executable.
// With it we can update other plugins, remove plugins,
// close connections, etc.
class Controller : public ServerPlugin {
 public:
  explicit Controller(Server* server);

  void ip_endpoint(IPEndPoint* ep) override;
  SockType sock_type() override;

  ProtocolHandler* NewProtocolHandler() override;

  std::string name() override { return m_name; }
 private:
  Server* m_server;

  static std::string m_name;
};

#endif  // SERVER_PLUGIN_CONTROLLER_CONTROLLER_H_
