#include "LogLibrary.h"
#include <iostream>
#include <mutex>
#include <chrono>
#include <fstream>

namespace {
    constexpr std::string_view RESET = "\033[0m";
    std::string_view ToColor(LogLevel level) {
        switch (level) {
            case LogLevel::Trace:   return "\033[90m";
            case LogLevel::Debug:   return "\033[36m";
            case LogLevel::Info:    return "\033[32m";
            case LogLevel::Warning: return "\033[33m";
            case LogLevel::Error:   return "\033[31m";
            case LogLevel::Fatal:   return "\033[97;41m";
        }
        return "\033[0m";
    }
    class ConsoleSink : public Sink{
        public:
            void Write(const Record& r) override {
                std::lock_guard<std::mutex> lock(m_lock);
                std::cout << ToColor(r.level) <<
                    std::format("[{:%H:%M:%S}] ",
                        std::chrono::floor<std::chrono::milliseconds>(std::chrono::system_clock::now()))<<
                    "[" << ToString(r.level) <<"] "<<
                    r.loggerName << ": "
                    << r.message << RESET << '\n';
            }
        private:
        std::mutex m_lock;
    };
}

std::shared_ptr<Logger> Log::s_Core;
std::shared_ptr<Logger> Log::s_Client;
Logger& Log::Core()   { return *s_Core; }
Logger& Log::Client() { return *s_Client; }
void Log::Init() {
    std::shared_ptr<Sink> auto_sink = std::make_shared<ConsoleSink>();
    s_Core = std::make_shared<Logger>("CORE");
    s_Client = std::make_shared<Logger>("CLIENT");
    s_Core->AddSink(auto_sink);
    s_Client->AddSink(auto_sink);
}