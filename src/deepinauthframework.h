#ifndef DEEPINAUTHFRAMEWORK_H
#define DEEPINAUTHFRAMEWORK_H

#include "authagent.h"

#include <QObject>

#define DISPLAY_ERROR_MESSAGE_CODE "DISPLAY_ERROR_MESSAGE_CODE"
#define DISPLAY_TEXT_INFO_CODE     "DISPLAY_TEXT_INFO_CODE"
#define RESPOND_RESULT             "RESPOND_RESULT"
#define PASSWORD                   "PASSWORD"

class DeepinAuthInterface;
class DeepinAuthFramework : public QObject
{
    Q_OBJECT
public:
    explicit DeepinAuthFramework(DeepinAuthInterface *inter, QObject *parent = nullptr);
    ~DeepinAuthFramework();

    friend class AuthAgent;

public slots:
    void SetUser(const QString &username);
    void Authenticate();
    void Cancel();

private:
    const QString RequestEchoOff(const QString &msg);
    const QString RequestEchoOn(const QString &msg);
    void DisplayErrorMsg(AuthAgent::Type type, const QString &msg);
    void DisplayTextInfo(AuthAgent::Type type, const QString &msg);
    void RespondResult(AuthAgent::Type type, const QString &msg);

private:
    AuthAgent *m_keyboard;
    AuthAgent *m_fprint;
    DeepinAuthInterface *m_interface;
};

#endif // DEEPINAUTHFRAMEWORK_H
