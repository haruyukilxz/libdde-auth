#include "deepinauthframework.h"
#include "../interface/deepinauthinterface.h"

#include <QTimer>
#include <QVariant>

DeepinAuthFramework::DeepinAuthFramework(DeepinAuthInterface *inter, QObject *parent)
    : QObject(parent)
    , m_interface(inter)
{
    m_keyboard = new AuthAgent(AuthAgent::Keyboard, this);
    m_fprint = new AuthAgent(AuthAgent::Fprint, this);
}

DeepinAuthFramework::~DeepinAuthFramework()
{
}

void DeepinAuthFramework::SetUser(const QString &username)
{
    m_keyboard->SetUser(username);
    m_fprint->SetUser(username);
}

void DeepinAuthFramework::Authenticate()
{
    if (!property(PASSWORD).toString().isEmpty()) {
        m_keyboard->Authenticate();
    }

    QTimer::singleShot(500, m_fprint, &AuthAgent::Authenticate);
}

void DeepinAuthFramework::Cancel()
{
    m_keyboard->Cancel();
    m_fprint->Cancel();
}

const QString DeepinAuthFramework::RequestEchoOff(const QString &msg)
{
    return property(PASSWORD).toString();
}

const QString DeepinAuthFramework::RequestEchoOn(const QString &msg)
{
    return msg;
}

void DeepinAuthFramework::DisplayErrorMsg(AuthAgent::Type type, const QString &msg)
{
    Q_UNUSED(type);

    m_interface->onDisplayErrorMsg(msg.toStdString());
}

void DeepinAuthFramework::DisplayTextInfo(AuthAgent::Type type, const QString &msg)
{
    Q_UNUSED(type);

    m_interface->onDisplayTextInfo(msg.toStdString());
}

void DeepinAuthFramework::RespondResult(AuthAgent::Type type, const QString &msg)
{
    if (type == AuthAgent::Fprint && msg.isEmpty()) return;

    m_interface->onPasswordResult(msg.toStdString());
}
