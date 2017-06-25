/**
 * @file server.cpp
 * @brief Networking server header file
 * @author StealthTech
 * @project Recast-client
 * @date 19.06.17
 * @email st3althtech@mail.ru
 *
 **/

#ifndef RECAST_NETWORKINGSERVER_H
#define RECAST_NETWORKINGSERVER_H

#include "network/Networking.hpp"

using namespace std;

class NetworkServer {
public:
    NetworkServer(uint32_t port, bool isTCP = false);
    void run();
    void shutdown();
    bool running() { return isRunning; }
private:
    uint32_t port;
    bool isTCP;
    volatile bool isRunning;

    void listenFor(shared_ptr<SocketTCP> client);
    void listenFor(shared_ptr<SocketUDP> client);
    string exchange(const string action);
    string check(const string action);
};

#endif //RECAST_NETWORKINGSERVER_H
