#ifndef CONFIGURABLEDBSCHEMA_H
#define CONFIGURABLEDBSCHEMA_H

#include <dbschema.h>

class DbSchemaPrivate;

class ConfigurableDbSchema : public DbSchema
{
public:
    ConfigurableDbSchema();

    virtual void setHdbXSettings(DbSettings *HdbXSettings);


protected:
    DbSchemaPrivate *d_ptr;
};

#endif // CONFIGURABLEDBSCHEMA_H
