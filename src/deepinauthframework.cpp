#include "deepinauthframework.h"

#include <QTimer>

DeepinAuthFramework::DeepinAuthFramework(QObject *parent)
    : QObject(parent)
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

    setProperty(DISPLAY_ERROR_MESSAGE_CODE, msg);
    emit displayErrorMsgChanged(msg);
}

void DeepinAuthFramework::DisplayTextInfo(AuthAgent::Type type, const QString &msg)
{
    Q_UNUSED(type);

    setProperty(DISPLAY_TEXT_INFO_CODE, msg);
    emit displayTextInfoChanged(msg);
}

void DeepinAuthFramework::RespondResult(AuthAgent::Type type, const QString &msg)
{
    if (type == AuthAgent::Fprint && msg.isEmpty()) return;

    setProperty(RESPOND_RESULT, msg);
    emit passwordResult(msg);
}
