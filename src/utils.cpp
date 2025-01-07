#include "utils.hpp"

void setupManufacturingModeMatch(
    const std::shared_ptr<sdbusplus::asio::connection>& conn,
    std::function<void(std::string mode)>&& handleSpecialModeChange)
{
    namespace rules = sdbusplus::bus::match::rules;
    static constexpr const char* SpecialModePath =
        "/xyz/openbmc_project/security/special_mode";
    static constexpr const char* SpecialModeInter =
        "xyz.openbmc_project.Control.Security.SpecialMode";
    const std::string SpecialModeIntefAdd =
        rules::interfacesAdded(SpecialModePath);
    static std::unique_ptr<sdbusplus::bus::match_t> SpecialModeIntefMatch =
        std::make_unique<sdbusplus::bus::match_t>(
            *conn, SpecialModeIntefAdd,
            [handleSpecialModeChange](sdbusplus::message_t& m) {
        sdbusplus::message::object_path path;
        using PropertyMap =
            boost::container::flat_map<std::string, std::variant<std::string>>;
        boost::container::flat_map<std::string, PropertyMap> interfaceAdded;
        m.read(path, interfaceAdded);
        auto interfiter = interfaceAdded.find(SpecialModeInter);
        if (interfiter == interfaceAdded.end())
        {
            return;
        }
        PropertyMap& propertyMap = interfiter->second;
        auto propertyIter = propertyMap.find("SpecialMode");
        if (propertyIter == propertyMap.end())
        {
            return;
        }
        auto* SpecialMode = std::get_if<std::string>(&propertyIter->second);
        std::cout << "lipb debug interface add" << std::endl;
        handleSpecialModeChange(*SpecialMode);
    });

    const std::string SpecicalModePropertyChange =
        rules::propertiesChanged(SpecialModePath, SpecialModeInter);

    static std::unique_ptr<sdbusplus::bus::match_t>
        SpecialModePropertyChangeMatch =
            std::make_unique<sdbusplus::bus::match_t>(
                *conn, SpecicalModePropertyChange,
                [handleSpecialModeChange](sdbusplus::message_t& m) {
        std::string interface;
        boost::container::flat_map<std::string, std::variant<std::string>>
            property;
        m.read(interface, property);
        auto iter = property.find("SpecialMode");
        if (iter == property.end())
        {
            return;
        }
        auto* SpecialMode = std::get_if<std::string>(&iter->second);
        std::cout << "lipb debug property change" << std::endl;
        handleSpecialModeChange(*SpecialMode);
    });

    conn->async_method_call(
        [handleSpecialModeChange](
            const boost::system::error_code& ec,
            const std::variant<std::string>& getManufactMode) {
        if (ec)
        {
            std::cout << "lipb debug : " << ec.message() << std::endl;
            return;
        }

        auto* manufactMode = std::get_if<std::string>(&getManufactMode);
        std::cout << "lipb debug property get" << std::endl;
        handleSpecialModeChange(*manufactMode);
    },
        "xyz.openbmc_project.Settings",
        "/xyz/openbmc_project/security/special_mode",
        "org.freedesktop.DBus.Properties", "Get", SpecialModeInter,
        "SpecialMode");
}
