#ifndef DEEPINAUTHINTERFACE_H
#define DEEPINAUTHINTERFACE_H

#include <string>

class DeepinAuthInterface
{
public:
    virtual void onDisplayErrorMsg(const std::string &msg) = 0;
    virtual void onDisplayTextInfo(const std::string &msg) = 0;
    virtual void onPasswordResult(const std::string &msg) = 0;
};

#endif // DEEPINAUTHINTERFACE_H
