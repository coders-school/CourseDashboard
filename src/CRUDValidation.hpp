#pragma once

#include <regex>
#include <stdexcept>

namespace crud
{
    inline bool validateEmail(const std::string& email)
    {
        std::regex l_validEmail("^([a-z0-9\\+_\\-]+)"
                                "(\\.[a-z0-9\\+_\\-]+)*@"
                                "([a-z0-9\\-]+\\.)+[a-z]{2,6}$");

        return std::regex_match(email, l_validEmail);
    }

//---------------------------------------------------------------------------------------
    inline bool validateName(const std::string& name)
    {
        std::regex l_validName("^[A-Z]{1}[a-z]*");
        return std::regex_match(name, l_validName);
    }

//---------------------------------------------------------------------------------------
    inline bool validateGitHubLink(const std::string& gitHubLink)
    {
        std::regex l_validGitHubLink("^[https://github.com/]+[a-z\\d](?:[a-z/d]|-(?=[a-z/d])){0,38}$");
        return std::regex_match(gitHubLink, l_validGitHubLink);
    }

//---------------------------------------------------------------------------------------

    inline bool validateFirecodeLink(const std::string& firecodeLink)
    {
        std::regex l_validFirecodeLink("^(https://www.firecode.io/)(pages/profile/)[0-9]{5,}");
        return std::regex_match(firecodeLink, l_validFirecodeLink);
    }

//---------------------------------------------------------------------------------------

    inline bool validateGroup(const std::string& group)
    {
        std::regex l_validGroup("^[A-Z]{1}[a-z]{1,}(-| ){0,1}[0-9]{0,8}$");
        return std::regex_match(group, l_validGroup);
    }
}
