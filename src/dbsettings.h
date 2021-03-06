#ifndef HDBXSETTINGS_H
#define HDBXSETTINGS_H

#include <map>
#include <string>

class DbSettings
{
public:
    DbSettings();

    ~DbSettings();

    void loadFromFile(const char *filename);

    void set(const char* key, const char *value);

    void set(const char *key, const double d);

    void set(const char *key, const int i);

    void set(const char *key,  bool b);

    bool hasKey(const char *key) const;

    long getInt(const char *key, bool *ok) const;

    std::string get(const char *key) const;

    std::string dbName() const;

    bool getBool(const char *key) const;

    double getDouble(const char* key, bool *ok) const;

    std::string getError() const;

    bool hasError() const;

private:
    std::map<std::string, std::string> mMap;
    std::string m_errorStr;
};

#endif // QUERYCONFIGURATION_H
