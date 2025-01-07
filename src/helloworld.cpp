#include <boost/asio/io_service.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>

int main()
{
    boost::asio::io_context io;

    auto conn = std::make_shared<sdbusplus::asio::connection>(io);
    sdbusplus::asio::object_server objectServer(conn, true);

    objectServer.add_manager("/xyz/openbmc_project/helloworld/sensors");
    objectServer.add_manager("/xyz/openbmc_project/helloworld/inventory");

    conn->request_name("xyz.openbmc_project.helloworld");

    io.run();

    return 0;
}
