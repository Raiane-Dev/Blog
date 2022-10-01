#include "../../includes/config/Logger.hpp"

Config::Logger::Logger()
{

    std::tm* current_date;
    char date_file[12];

    std::strftime(date_file, 50, "%d/%m/%y", current_date);

    plog::init (plog::debug, date_file);
    plog::init (plog::info, date_file);
    plog::init (plog::warning, date_file);

    plog::init (plog::error, date_file);
    plog::init (plog::fatal, date_file);
    plog::init (plog::debug, date_file);

    PLOGD << "INITIALIZING...";

    Logger& init(Severity maxSeverity, const wchar_t* fileName, size_t maxFileSize = 0, int maxFiles = 0);
    
}