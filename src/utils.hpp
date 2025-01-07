#include <boost/container/flat_map.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/bus/match.hpp>
#include <boost/system/error_code.hpp>

#include <variant>
#include <iostream>

void setupManufacturingModeMatch(
    const std::shared_ptr<sdbusplus::asio::connection>& conn,
    std::function<void(std::string mode)>&& handleSpecialModeChange);
