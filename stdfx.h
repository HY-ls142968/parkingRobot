#ifndef STDFX_H
#define STDFX_H

#include <QtCore>
#include <QString>
#include <functional>
#include "ThreadPool.h"
#include "spdlog.h"

extern std::shared_ptr<spdlog::logger> rcsLog;
extern QJsonObject rcsConfig;
extern QString JsonToString(QJsonObject json);
extern QByteArray JsonToQByteArray(QJsonObject json);
extern bool JsonReaderParse(QByteArray msg, QJsonObject* root, QJsonParseError* errs);


#endif // STDFX_H
