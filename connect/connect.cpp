#include <asio.hpp>
#include <string>
#include <fstream>
#include <sys/types.h>

using namespace asio;
using namespace asio::ip;

static io_service gService;
static int numClients = 0;

namespace il {

class Client {
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

int main(int argc, char* argv[]) {
    // TODO: handle sigint

    // write the pid file
    std::ofstream f("pid/" + std::to_string(getpid()));
    f.close();

    il::Client client;
    tcp::endpoint ep(address_v4::from_string("127.0.0.1"), 8088);
    client.connect(ep);

    gService.run();

    // TODO: write number of connections

    return 0;
}

namespace il {

Client::Client()
    :   socket_(gService)
{

}

void Client::connect(const tcp::endpoint& ep) {
    socket_.async_connect(ep, std::bind(&Client::onConnect, this, std::placeholders::_1));
}

void Client::onConnect(const std::error_code& error) {
    if (!error) {

    } else {

    }
}

void Client::read() {
    async_read(socket_, buffer_, std::bind(&Client::onRead, this, std::placeholders::_1));
}

void Client::onRead(const std::error_code& error) {
    if (!error) {

    } else {

    }
}

Client::~Client() {

}

} // namespace il
