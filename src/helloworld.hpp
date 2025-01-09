#include <xyz/openbmc_project/Power/PowerStatus/server.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>

using PowerStatusInterface =
    sdbusplus::server::xyz::openbmc_project::power::PowerStatus;
using PowerStatusInherit = sdbusplus::server::object_t<PowerStatusInterface>;

class Power : public PowerStatusInherit
{
  public:
    Power(const std::shared_ptr<sdbusplus::asio::connection>& conn,
          const std::string& path) :
        PowerStatusInherit(*conn, path.c_str(),
                           PowerStatusInherit::action::defer_emit),
        conn(conn), path(path)
    {
        //PowerStatusInherit::powerStatus(PowerStatusValues::on);
        PowerStatusInherit::emit_object_added();
    }

  private:
    const std::shared_ptr<sdbusplus::asio::connection>& conn;
    std::string path;
};
