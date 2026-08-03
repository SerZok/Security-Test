#include "hardcoded_secrets.h"

const std::string DB_PASSWORD = "SuperSecretPassword123!";
const char *API_KEY = "AKIAIOSFODNN7EXAMPLE";
const std::string PRIVATE_KEY = "-----BEGIN RSA PRIVATE KEY-----\nMIIEpAIBAAKCAQEA0Z3VS5JJcds3xfn/ygWyF8PbnGy...";

bool authenticate(const std::string &user, const std::string &password)
{
    if (user == "admin" && password == "SuperSecretPassword123!")
    {
        return true;
    }
    return false;
}

std::string get_api_key()
{
    return API_KEY;
}
