#ifndef TEST_URL_HANLDERS_HPP
#define TEST_URL_HANLDERS_HPP

#include <QObject>
#include <QUrl>

#include "testlib_global.hpp"

namespace Testlib
{

class TESTLIB_EXPORT UrlVisitTestHandler: public QObject
{
    Q_OBJECT
public:
    UrlVisitTestHandler() {}
    explicit UrlVisitTestHandler(const QUrl &url):
        m_url(url)
    {}
    bool visited() const { return m_visited; }
    QUrl getUrl() const { return m_url; }
public slots:
    void handle(const QUrl &url)
    {
        m_visited = m_visited || (url == m_url);
    }
    void reset() { m_visited = false; }
    void setUrl(const QUrl &url)
    {
        if (m_url != url)
        {
            reset();
        }
        m_url = url;
    }
private:
    QUrl m_url;
    bool m_visited = false;
};

class TESTLIB_EXPORT LastVisitedUrlHandler: public QObject
{
    Q_OBJECT
public:
    LastVisitedUrlHandler() {}
    bool visited() const { return !m_url.isEmpty(); }
    QUrl getUrl() const { return m_url; }
public slots:
    void handle(const QUrl &url)
    {
        m_url = url;
    }
    void reset() { m_url.clear(); }
private:
    QUrl m_url;
};

class TESTLIB_EXPORT NullUrlHandler: public QObject
{
    Q_OBJECT
public slots:
    void handle(const QUrl &) {}
};

} // namespace Testlib
#endif // TEST_URL_HANLDERS_HPP
