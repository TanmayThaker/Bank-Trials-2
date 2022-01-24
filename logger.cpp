#include "logger.h"

LogPriority Logger::priority = TracePriority;
const char *Logger::filepaths[] = {"data/Logs/TraceLogs.txt", "data/Logs/DebugLogs.txt", "data/Logs/InfoLogs.txt", "data/Logs/WarningLogs.txt", "data/Logs/ErrorLogs.txt", "data/Logs/CriticalLogs.txt"};
FILE **Logger::files = NULL;
string Logger::databaseFileName = "data/database.db";
mutex Logger::logMutex;

void Logger::SetPriority(LogPriority new_priority)
{
    priority = new_priority;
}

void Logger::EnableFileOutput()
{
    enable_file_output();
}

void Logger::CloseFileOutput()
{
    free_file();
}

void Logger::enable_file_output()
{
    int i;
    if (files == NULL)
    {
        files = (FILE **)malloc(numberOfPriorities * sizeof(FILE *));
    }
    for (i = 0; i < numberOfPriorities; i++)
    {
        files[i] = fopen(filepaths[i], "a");
    }
}

void Logger::free_file()
{
    if (files)
    {
        for (int i = 0; i < numberOfPriorities; i++)
        {
            fclose(files[i]);
        }
        free(files);
        files = NULL;
    }
}