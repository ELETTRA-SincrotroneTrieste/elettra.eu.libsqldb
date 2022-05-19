#ifndef MYSQLHDBSCHEMAPRIVATE_H
#define MYSQLHDBSCHEMAPRIVATE_H

#include <pthread.h>

#define MAXERRORLEN 8192

class ResultListener;
class XVariantList;
class DbSettings;

class DbSchemaPrivate
{
public:
    DbSchemaPrivate() {}

    ResultListener *resultListenerI;

    int notifyEveryPercent;

    pthread_mutex_t mutex;

    XVariantList *variantList;

    DbSettings *hdbxSettings;

    char errorMessage[MAXERRORLEN];

    size_t totalRowCnt;

    bool isCancelled;
};

#endif // MYSQLHDBSCHEMAPRIVATE_H
