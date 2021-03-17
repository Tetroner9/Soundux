#if defined(__linux__)
#include "../../misc/misc.hpp"
#include "../systeminfo.hpp"
#include <fancy.hpp>

std::string SystemInfo::getSystemInfo()
{
    std::string result;
    if (Soundux::Helpers::exec("lsb_release -a", result))
    {
        if (result.empty())
        {
            Fancy::fancy.logTime().warning() << "lsb_release output was empty!" << std::endl;
            result = "lsb_release failed";
        }
    }
    else
    {
        Fancy::fancy.logTime().warning() << "lsb_release failed!" << std::endl;
    }

    auto *desktopEnv = std::getenv("XDG_CURRENT_DESKTOP"); // NOLINT
    if (desktopEnv != nullptr)
    {
        result += "\nCurrent Desktop: " + std::string(desktopEnv) + "\n";
    }
    else
    {
        Fancy::fancy.logTime() << "XDG_CURRENT_DESKTOP not set" << std::endl;
    }

    return result;
}
#endif