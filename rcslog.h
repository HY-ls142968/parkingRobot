#ifndef RCSLOG_H
#define RCSLOG_H

#include "stdfx.h"
#include <functional>
#include <deque>

class Log : public spdlog::sinks::base_sink < std::mutex >
{
public:
    Log(QString name = "log", int fileSize = 5)
    {
        fileSize = fileSize < 5 ? 5 : (fileSize>100? 100 : fileSize);
        if (name.isEmpty())
            name = "log";
        logger = spdlog::rotating_logger_mt(name.toStdString(), name.toStdString() + ".txt", 1024 * 1024 * fileSize, 1);
        logger->set_pattern("%D, %v");
    }
    Log(std::shared_ptr<spdlog::logger> _logger):logger(_logger){}
    Log(QJsonObject& config) :
        Log(config.value("name").toString(), config.value("size").toInt()){}
    ~Log(){}
    std::function<void(const char*, int)> postLog;
protected:
    void _sink_it(const spdlog::details::log_msg& msg) override
    {
        std::unique_lock<std::mutex> lock(writeMutex);
        msgList.push_back(msg.formatted.c_str());
        if (msgList.size() > 20)
            msgList.pop_front();
        if (postLog)
            postLog(msgList.back().c_str(), msg.level);
        logger->log(msg.level, msgList.back().c_str());
    }
    void _flush() override{ logger->flush(); }
private:
    std::mutex writeMutex;
    std::deque<std::string> msgList;
    std::shared_ptr<spdlog::logger> logger;
};
#endif // RCSLOG_H
