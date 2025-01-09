#include <boost/asio/io_service.hpp>
#include <helloworld.hpp>
#include <utils.hpp>

#include <iostream>
#include <memory>

int main()
{
    boost::asio::io_context io;

    auto conn = std::make_shared<sdbusplus::asio::connection>(io);
    sdbusplus::asio::object_server objectServer(conn, true);

    objectServer.add_manager("/xyz/openbmc_project/helloworld/sensors");
    objectServer.add_manager("/xyz/openbmc_project/helloworld/inventory");

    setupManufacturingModeMatch(conn, [](std::string mode) {
        std::cout << "lipb debug : " << mode << std::endl;
    });

    conn->request_name("xyz.openbmc_project.helloworld");

    auto hello_ptr =
        std::make_unique<Power>(conn, "/xyz/openbmc_project/helloworld/power");

    hello_ptr->powerStatus(static_cast<PowerStatusInterface::PowerStatusValues>(1));
    hello_ptr->name("CRPS2000NC");

    io.run();

    return 0;
}
