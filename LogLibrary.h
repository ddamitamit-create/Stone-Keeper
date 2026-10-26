#pragma once
#include <format>
#include <string>
#include <vector>
#include <memory>

enum class LogLevel {Trace, Debug, Info, Warning, Error, Fatal}; //the severity of the message

inline std::string_view ToString(LogLevel level) { //write the Loglevel in a string
    switch (level) {
        case LogLevel::Trace:   return "TRACE";
        case LogLevel::Debug:   return "DEBUG";
        case LogLevel::Info:    return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error:   return "ERROR";
        case LogLevel::Fatal:   return "FATAL";
    }
    return "UNKNOWN";
}

struct Record{ //how the record (which is what will be printed) is built
    LogLevel level;
    const std::string& loggerName;
    std::string message;
};

struct Sink { // basically that's where the Record is kept
    virtual ~Sink() = default;
    virtual void Write(const Record&) = 0;
};

class Logger {
    public:
        Logger(std::string name) : m_Name(std::move(name)){} // constructor
        void SetLevel(LogLevel level) {m_MinLevel = level;}
        void AddSink(std::shared_ptr<Sink> sink) {m_Sinks.push_back(std::move(sink));}

    template<class... Args>
    void Log(LogLevel lvl, std::format_string<Args...> fmt, Args&&... args) { //making the actual record and writing it
            if (lvl < m_MinLevel || lvl != LogLevel::Debug) return;
            Record r{lvl, m_Name, std::format(fmt, std::forward<Args>(args)...)};
            for (auto& s : m_Sinks) s->Write(r);
        }

    private: //variables
        std::string m_Name;
        LogLevel m_MinLevel = LogLevel::Trace;
        std::vector < std::shared_ptr<Sink>> m_Sinks;
};