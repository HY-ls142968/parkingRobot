#include "stdfx.h"

std::shared_ptr<spdlog::logger> rcsLog = spdlog::stdout_color_mt("console");

static QJsonObject loadConfig(QString filename)
{
    QJsonObject js;
    QByteArray ba;
    QJsonParseError err;
    QFile fs(filename);
    if(fs.open(QIODevice::ReadOnly))
    {
        ba = fs.readAll();
        rcsLog->info("{}",ba.data());
    }
    bool isJson = JsonReaderParse(ba,&js,&err);
    if(!isJson)
    {
        rcsLog->error("配置文件不是标准Json文件!");
    }
    return js;
}

QJsonObject rcsConfig = loadConfig("RcsConfig.json");

QString JsonToString(QJsonObject json)
{
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    return strJson;
}

QByteArray JsonToQByteArray(QJsonObject json)
{
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    return byteArray;
}

bool JsonReaderParse(QByteArray msg, QJsonObject* root, QJsonParseError* errs)
{
    QJsonDocument document = QJsonDocument::fromJson(msg, errs);  // 转化为 JSON 文档
    if (!document.isNull() && (errs->error == QJsonParseError::NoError)) {
        if (document.isObject())
        {
            *root = document.object();
            return true;
        }
        else
            return false;
    }
    return false;
}
