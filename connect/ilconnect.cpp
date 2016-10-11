#include <asio.hpp>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <csignal>
#include <atomic>
#include <iostream>

using namespace asio;
using namespace asio::ip;

static io_service gService;
static std::atomic<std::uint64_t> gCount;
static std::string pidPath;

namespace il {

class Client : public std::enable_shared_from_this<Client> {
public:
                            Client();
                            ~Client();

    void                    connect(const tcp::endpoint& ep);
    void                    onConnect(const std::error_code& error);
    void                    read();
    void                    onRead(const std::error_code& error);

private:
    tcp::socket             socket_;
    streambuf               buffer_;
};

} // namespace il

void end(int sig) {
    // write number of connected sockets
    std::ofstream f(pidPath + '/' + std::to_string(getpid()));
    f << gCount.load();
    f.close();

    exit(0);
}

int main(int argc, char* argv[]) {
    std::signal(SIGTERM, end);

    if (argc < 3) {
        std::cout << "Usage: ./connect ip port output_path" << std::endl;
        exit(-1);
    }

    pidPath = argv[3];

    // write the pid file
    std::ofstream f(pidPath + '/' + std::to_string(getpid()));
    f.close();

    gCount = 0;
    tcp::endpoint ep(address_v4::from_string(argv[1]), std::stoi(argv[2]));

    for (int i = 0; i < 1000; ++i) {
        auto client = std::make_shared<il::Client>();
        client->connect(ep);
    }

    gService.run();

    return 0;
}

namespace il {

Client::Client()
    :   socket_(gService)
{

}

void Client::connect(const tcp::endpoint& ep) {
    socket_.async_connect(ep, std::bind(&Client::onConnect,
                                        shared_from_this(), std::placeholders::_1));
}

void Client::onConnect(const std::error_code& error) {
    if (!error) {
        ++gCount;
        read();
    } else {
//        std::cout << error.message();
    }
}

void Client::read() {
    async_read(socket_, buffer_, std::bind(&Client::onRead,
                                           shared_from_this(), std::placeholders::_1));
}

void Client::onRead(const std::error_code& error) {
    if (!error) {

    } else {
        --gCount;
//        std::cout << error.message();
    }
}

Client::~Client() {

}

} // namespace il
